array A_use = [3] A
constant a_use = a
array T_use = [3] T
array S_use = [3] S
constant E_use = E.X

module M {
  array A_use = [3] A
  constant a_use = a
  array T_use = [3] T
  array S_use = [3] S
  constant E_use = E.X
}

passive component C2 {
  sync input port P_use: P
  array C1_A_use = [3] C1.A
  constant C1_a_use = C1.a
  array C1_S_use = [3] C1.S
  array C1_T_use = [3] C1.T
  constant C1_E_use = C1.E.X
}

active component C3 {
  async input port P_use: P
  command recv port cmdIn
  command reg port cmdRegOut
  command resp port cmdRespOut
  event port eventOut
  param get port paramGetOut
  param set port paramSetOut
  telemetry port tlmOut
  text event port textEventOut
  time get port timeGetOut
}

instance c12: C1 base id 0x200

topology T2 {
  import T1
  instance c11
}

module M {

  instance c12: C1 base id 0x200

  topology T2 {
    import T1
    instance c11
  }

}
