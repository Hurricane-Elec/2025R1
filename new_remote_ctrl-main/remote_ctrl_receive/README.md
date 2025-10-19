# 遥控器接收

此模块为主板接收遥控器数据，遥控器本身不使用。

## 依赖模块

- `message_protocol`

## API

- `remote_key_event_t` 定义按键事件回调函数的事件。有按下、长按、抬起事件。回调函数可以根据事件执行相应的操作。
- `remote_key_callback_t` 定义按键回调函数指针类型。参数：
  - `key` 按下的按键
  - `event` 按键事件

- `remote_receive_callback` 此函数用于注册`msg_protocol`的回调，需要加到消息的回调中。例如：
  ``` C
  message_register_recv_callback(MSG_ID_REMOTE, remote_receive_callback);
  ```
- `remote_receive_callback` 注册按键事件回调函数
- `remote_unregister_key_callback` 清除注册按键事件回调函数