module Fw {

  port DpBufferRecv
  port DpBufferRequest
  port DpBufferSend

}

passive component C {

  product request port productRequestOut
  sync product recv port productRecvIn
  product send port productSendOut

  @ A container with no ID and no default priority
  product container Basic

  @ A container with ID and no default priority
  product container IdOnly id 0x100

  @ A container with ID and default priority
  product container IdPriority id 0x200 default priority 3

  @ A record with no ID
  product record Basic: U32

  @ A record with an ID
  product record Id: U32 id 0x100

}