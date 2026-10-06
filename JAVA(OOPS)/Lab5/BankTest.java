class BankAccount {
    private String accountHolder;
    private double balance; 

    
    public BankAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        if (initialBalance >= 0) {
            this.balance = initialBalance;
        } else {
            this.balance = 0;
            System.out.println("Initial balance cannot be negative. Set to 0.");
        }
    }

    
    public double getBalance() {
        return balance;
    }

    public String getAccountHolder() {
        return accountHolder;
    }

    
    public class Transaction {
        
        
        public void deposit(double amount) {
            if (amount > 0) {
                balance += amount; 
                System.out.println("Successfully deposited: $" + amount);
                System.out.println("New Balance: $" + balance);
            } else {
                System.out.println("Deposit amount must be greater than zero.");
            }
        }

        
        public void withdraw(double amount) {
            if (amount <= 0) {
                System.out.println("Withdrawal amount must be greater than zero.");
            } else if (amount > balance) {
                System.out.println("Transaction Failed: Insufficient funds! Current balance is $" + balance);
            } else {
                balance -= amount;
                System.out.println("Successfully withdrew: $" + amount);
                System.out.println("Remaining Balance: $" + balance);
            }
        }
    }
}

public class BankTest {
    public static void main(String[] args) {
        
        BankAccount myAccount = new BankAccount("Natiq", 5000.0);

        
        BankAccount.Transaction txn = myAccount.new Transaction();

        System.out.println("Account Holder: " + myAccount.getAccountHolder());
        System.out.println("Initial Balance: $" + myAccount.getBalance());
        

        
        txn.deposit(1500.0);
        

        
        txn.withdraw(2000.0);
        

        txn.withdraw(10000.0);
    }
}