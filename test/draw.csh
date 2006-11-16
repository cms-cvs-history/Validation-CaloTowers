#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh


    root  -q hcaloval.C\(\"HB\"\)
    root  -q hcaloval.C\(\"HE\"\)
    root  -q hcaloval.C\(\"HF\"\)
 
