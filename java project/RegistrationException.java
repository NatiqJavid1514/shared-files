/** User-defined (checked) exception for invalid registration/management operations. */
public class RegistrationException extends Exception {
    public RegistrationException(String message) {
        super(message);
    }
}
