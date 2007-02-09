#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh


    root  -q HcalOval.C\(\"HB\",\"gif\"\)
    root  -q HcalOval.C\(\"HE\",\"gif\"\)
    root  -q HcalOval.C\(\"HF\",\"gif\"\)
 
