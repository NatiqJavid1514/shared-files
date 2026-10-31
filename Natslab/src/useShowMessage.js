import { useState } from "react";

function useShowMessage(text) {
  const [visible, setVisible] = useState(false);

  const show = () => setVisible(true);
  const hide = () => setVisible(false);
  const toggle = () => setVisible(!visible);

  const message = visible ? text : "";

  return { message, visible, show, hide, toggle };
}

export default useShowMessage;