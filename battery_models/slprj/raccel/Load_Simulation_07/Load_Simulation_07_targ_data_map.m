  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 222;
      section.data(222)  = dumData; %prealloc
      
	  ;% rtP.u2volts10AhLeadAcidbattery_BatType
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.u2v10AhLiFePO4_BatType
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.u2volts10AhNiMHbattery_BatType
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.u2volts10AhLeadAcidbattery_SOC
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.u2v10AhLiFePO4_SOC
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.u2volts10AhNiMHbattery_SOC
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Constant1_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Constant_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Saturation3_UpperSat
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.Saturation3_LowerSat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.Constant10_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.Switch3_Threshold
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.itinit1_X0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.Constant13_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Switch5_Threshold
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.R2_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.Currentfilter_A
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.Currentfilter_C
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.Constant_Value_alteb1itig
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.inti_UpperSat
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.inti_LowerSat
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.Gain_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.Constant9_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.StateSpace_A
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.StateSpace_B
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.StateSpace_C
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtP.StateSpace_X0
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtP.Constant5_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtP.Constant4_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtP.Switch_Threshold
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtP.Constant4_Value_baux3n4syi
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtP.R3_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtP.Constant_Value_ox3fg1go0h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtP.Constant1_Value_ena3bvbnod
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtP.Constant3_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtP.Constant2_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtP.Constant14_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtP.Constant15_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtP.Constant16_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtP.Switch6_Threshold
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtP.Currentfilter1_A
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtP.Currentfilter1_C
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtP.Constant7_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtP.Constant6_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtP.Switch2_Threshold
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtP.Constant3_Value_iqsu23z4ce
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtP.Constant2_Value_cdqfgwpsti
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtP.Switch1_Threshold
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtP.R1_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 3649;
	
	  ;% rtP.StateSpace_P1_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 7249;
	
	  ;% rtP.StateSpace_P1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 7251;
	
	  ;% rtP.StateSpace_P2_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 7254;
	
	  ;% rtP.StateSpace_P2
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 7256;
	
	  ;% rtP.StateSpace_P3_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 7260;
	
	  ;% rtP.StateSpace_P4_Size
	  section.data(57).logicalSrcIdx = 57;
	  section.data(57).dtTransOffset = 7262;
	
	  ;% rtP.StateSpace_P4
	  section.data(58).logicalSrcIdx = 58;
	  section.data(58).dtTransOffset = 7264;
	
	  ;% rtP.donotdeletethisgain_Gain
	  section.data(59).logicalSrcIdx = 59;
	  section.data(59).dtTransOffset = 7462;
	
	  ;% rtP.R_Gain
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 7463;
	
	  ;% rtP.R4_Gain
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 7464;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 7465;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(63).logicalSrcIdx = 63;
	  section.data(63).dtTransOffset = 7466;
	
	  ;% rtP.Constant1_Value_p0nk0e4k4t
	  section.data(64).logicalSrcIdx = 64;
	  section.data(64).dtTransOffset = 7467;
	
	  ;% rtP.Constant_Value_b2oae4kl4u
	  section.data(65).logicalSrcIdx = 65;
	  section.data(65).dtTransOffset = 7468;
	
	  ;% rtP.Saturation3_UpperSat_matxumbq22
	  section.data(66).logicalSrcIdx = 66;
	  section.data(66).dtTransOffset = 7469;
	
	  ;% rtP.Saturation3_LowerSat_ikhjztqrap
	  section.data(67).logicalSrcIdx = 67;
	  section.data(67).dtTransOffset = 7470;
	
	  ;% rtP.Constant10_Value_b4me2hmi3i
	  section.data(68).logicalSrcIdx = 68;
	  section.data(68).dtTransOffset = 7471;
	
	  ;% rtP.Switch3_Threshold_f11xead0ed
	  section.data(69).logicalSrcIdx = 69;
	  section.data(69).dtTransOffset = 7472;
	
	  ;% rtP.itinit1_X0_izz5uwg0q1
	  section.data(70).logicalSrcIdx = 70;
	  section.data(70).dtTransOffset = 7473;
	
	  ;% rtP.Constant13_Value_bofm4evjtq
	  section.data(71).logicalSrcIdx = 71;
	  section.data(71).dtTransOffset = 7474;
	
	  ;% rtP.Switch5_Threshold_gd4feiqqyu
	  section.data(72).logicalSrcIdx = 72;
	  section.data(72).dtTransOffset = 7475;
	
	  ;% rtP.R2_Gain_bxxpczbi0a
	  section.data(73).logicalSrcIdx = 73;
	  section.data(73).dtTransOffset = 7476;
	
	  ;% rtP.Currentfilter_A_hpeprc3wrq
	  section.data(74).logicalSrcIdx = 74;
	  section.data(74).dtTransOffset = 7477;
	
	  ;% rtP.Currentfilter_C_ghxfrv2shu
	  section.data(75).logicalSrcIdx = 75;
	  section.data(75).dtTransOffset = 7478;
	
	  ;% rtP.Constant_Value_o5texc1pzk
	  section.data(76).logicalSrcIdx = 76;
	  section.data(76).dtTransOffset = 7479;
	
	  ;% rtP.inti_UpperSat_dal2xymi3h
	  section.data(77).logicalSrcIdx = 77;
	  section.data(77).dtTransOffset = 7480;
	
	  ;% rtP.inti_LowerSat_plajszqohf
	  section.data(78).logicalSrcIdx = 78;
	  section.data(78).dtTransOffset = 7481;
	
	  ;% rtP.Gain_Gain_fvqpvk3pvf
	  section.data(79).logicalSrcIdx = 79;
	  section.data(79).dtTransOffset = 7482;
	
	  ;% rtP.Constant9_Value_jc35dhdc3v
	  section.data(80).logicalSrcIdx = 80;
	  section.data(80).dtTransOffset = 7483;
	
	  ;% rtP.StateSpace_A_lj2d3hqe0x
	  section.data(81).logicalSrcIdx = 81;
	  section.data(81).dtTransOffset = 7484;
	
	  ;% rtP.StateSpace_B_mjohccgfqz
	  section.data(82).logicalSrcIdx = 82;
	  section.data(82).dtTransOffset = 7485;
	
	  ;% rtP.StateSpace_C_iee0yjqzes
	  section.data(83).logicalSrcIdx = 83;
	  section.data(83).dtTransOffset = 7486;
	
	  ;% rtP.StateSpace_X0_hyto3shui2
	  section.data(84).logicalSrcIdx = 84;
	  section.data(84).dtTransOffset = 7487;
	
	  ;% rtP.Constant5_Value_fafteqsipq
	  section.data(85).logicalSrcIdx = 85;
	  section.data(85).dtTransOffset = 7488;
	
	  ;% rtP.Constant4_Value_jum4bwpjax
	  section.data(86).logicalSrcIdx = 86;
	  section.data(86).dtTransOffset = 7489;
	
	  ;% rtP.Switch_Threshold_abfzybubnv
	  section.data(87).logicalSrcIdx = 87;
	  section.data(87).dtTransOffset = 7490;
	
	  ;% rtP.Constant4_Value_db1mnqkkob
	  section.data(88).logicalSrcIdx = 88;
	  section.data(88).dtTransOffset = 7491;
	
	  ;% rtP.R3_Gain_bqq4aa4t3o
	  section.data(89).logicalSrcIdx = 89;
	  section.data(89).dtTransOffset = 7492;
	
	  ;% rtP.Constant_Value_mscbjvxnfy
	  section.data(90).logicalSrcIdx = 90;
	  section.data(90).dtTransOffset = 7493;
	
	  ;% rtP.Constant1_Value_e3wa3mydbv
	  section.data(91).logicalSrcIdx = 91;
	  section.data(91).dtTransOffset = 7494;
	
	  ;% rtP.Constant3_Value_f2btqjtsos
	  section.data(92).logicalSrcIdx = 92;
	  section.data(92).dtTransOffset = 7495;
	
	  ;% rtP.Constant2_Value_fa544zy0zf
	  section.data(93).logicalSrcIdx = 93;
	  section.data(93).dtTransOffset = 7496;
	
	  ;% rtP.Constant14_Value_mkv5pnyukp
	  section.data(94).logicalSrcIdx = 94;
	  section.data(94).dtTransOffset = 7497;
	
	  ;% rtP.Constant15_Value_ad54pn3wr2
	  section.data(95).logicalSrcIdx = 95;
	  section.data(95).dtTransOffset = 7498;
	
	  ;% rtP.Constant16_Value_cjh5ma2c3k
	  section.data(96).logicalSrcIdx = 96;
	  section.data(96).dtTransOffset = 7499;
	
	  ;% rtP.Switch6_Threshold_htoqtnapgo
	  section.data(97).logicalSrcIdx = 97;
	  section.data(97).dtTransOffset = 7500;
	
	  ;% rtP.Currentfilter1_A_cqp1aqrh0k
	  section.data(98).logicalSrcIdx = 98;
	  section.data(98).dtTransOffset = 7501;
	
	  ;% rtP.Currentfilter1_C_o13iba3s0t
	  section.data(99).logicalSrcIdx = 99;
	  section.data(99).dtTransOffset = 7502;
	
	  ;% rtP.Constant7_Value_ncodhoosuz
	  section.data(100).logicalSrcIdx = 100;
	  section.data(100).dtTransOffset = 7503;
	
	  ;% rtP.Constant6_Value_hd4fth2fjz
	  section.data(101).logicalSrcIdx = 101;
	  section.data(101).dtTransOffset = 7504;
	
	  ;% rtP.Switch2_Threshold_l01luurl0n
	  section.data(102).logicalSrcIdx = 102;
	  section.data(102).dtTransOffset = 7505;
	
	  ;% rtP.Constant3_Value_n51n10aq0o
	  section.data(103).logicalSrcIdx = 103;
	  section.data(103).dtTransOffset = 7506;
	
	  ;% rtP.Constant2_Value_hvybrtqmxz
	  section.data(104).logicalSrcIdx = 104;
	  section.data(104).dtTransOffset = 7507;
	
	  ;% rtP.Switch1_Threshold_mcownc3hf5
	  section.data(105).logicalSrcIdx = 105;
	  section.data(105).dtTransOffset = 7508;
	
	  ;% rtP.R1_Gain_frm0s5nenw
	  section.data(106).logicalSrcIdx = 106;
	  section.data(106).dtTransOffset = 7509;
	
	  ;% rtP.StateSpace_P1_Size_o5kda433ud
	  section.data(107).logicalSrcIdx = 107;
	  section.data(107).dtTransOffset = 7510;
	
	  ;% rtP.StateSpace_P1_lgsdqm3bih
	  section.data(108).logicalSrcIdx = 108;
	  section.data(108).dtTransOffset = 7512;
	
	  ;% rtP.StateSpace_P2_Size_bulgjz5eca
	  section.data(109).logicalSrcIdx = 109;
	  section.data(109).dtTransOffset = 7515;
	
	  ;% rtP.StateSpace_P2_lhxftost1h
	  section.data(110).logicalSrcIdx = 110;
	  section.data(110).dtTransOffset = 7517;
	
	  ;% rtP.StateSpace_P3_Size_phw4ixie5t
	  section.data(111).logicalSrcIdx = 111;
	  section.data(111).dtTransOffset = 7521;
	
	  ;% rtP.StateSpace_P4_Size_br3dqazqmh
	  section.data(112).logicalSrcIdx = 113;
	  section.data(112).dtTransOffset = 7523;
	
	  ;% rtP.StateSpace_P4_ah0hhhtenk
	  section.data(113).logicalSrcIdx = 114;
	  section.data(113).dtTransOffset = 7525;
	
	  ;% rtP.donotdeletethisgain_Gain_hql5qzrmqi
	  section.data(114).logicalSrcIdx = 115;
	  section.data(114).dtTransOffset = 7675;
	
	  ;% rtP.R_Gain_leocntiara
	  section.data(115).logicalSrcIdx = 116;
	  section.data(115).dtTransOffset = 7676;
	
	  ;% rtP.R4_Gain_gi4xenlaa1
	  section.data(116).logicalSrcIdx = 117;
	  section.data(116).dtTransOffset = 7677;
	
	  ;% rtP.Saturation_UpperSat_mtqq4gsywh
	  section.data(117).logicalSrcIdx = 118;
	  section.data(117).dtTransOffset = 7678;
	
	  ;% rtP.Saturation_LowerSat_gwhczn143q
	  section.data(118).logicalSrcIdx = 119;
	  section.data(118).dtTransOffset = 7679;
	
	  ;% rtP.Constant1_Value_nxh5i5seoh
	  section.data(119).logicalSrcIdx = 120;
	  section.data(119).dtTransOffset = 7680;
	
	  ;% rtP.Constant_Value_irl5fvnkc1
	  section.data(120).logicalSrcIdx = 121;
	  section.data(120).dtTransOffset = 7681;
	
	  ;% rtP.Saturation3_UpperSat_ntsul5erig
	  section.data(121).logicalSrcIdx = 122;
	  section.data(121).dtTransOffset = 7682;
	
	  ;% rtP.Saturation3_LowerSat_b5p1gj4cuc
	  section.data(122).logicalSrcIdx = 123;
	  section.data(122).dtTransOffset = 7683;
	
	  ;% rtP.Constant10_Value_lc4vxfnhde
	  section.data(123).logicalSrcIdx = 124;
	  section.data(123).dtTransOffset = 7684;
	
	  ;% rtP.Switch3_Threshold_dyzy5hn0uo
	  section.data(124).logicalSrcIdx = 125;
	  section.data(124).dtTransOffset = 7685;
	
	  ;% rtP.itinit1_X0_auy3ty1z4l
	  section.data(125).logicalSrcIdx = 126;
	  section.data(125).dtTransOffset = 7686;
	
	  ;% rtP.Constant13_Value_mqbxzfv4z4
	  section.data(126).logicalSrcIdx = 127;
	  section.data(126).dtTransOffset = 7687;
	
	  ;% rtP.Switch5_Threshold_aipebitqdl
	  section.data(127).logicalSrcIdx = 128;
	  section.data(127).dtTransOffset = 7688;
	
	  ;% rtP.R2_Gain_lmwx4sb00n
	  section.data(128).logicalSrcIdx = 129;
	  section.data(128).dtTransOffset = 7689;
	
	  ;% rtP.Currentfilter_A_cwwxbi13u0
	  section.data(129).logicalSrcIdx = 130;
	  section.data(129).dtTransOffset = 7690;
	
	  ;% rtP.Currentfilter_C_mskf05lo23
	  section.data(130).logicalSrcIdx = 131;
	  section.data(130).dtTransOffset = 7691;
	
	  ;% rtP.Constant_Value_ezg4nv1jai
	  section.data(131).logicalSrcIdx = 132;
	  section.data(131).dtTransOffset = 7692;
	
	  ;% rtP.inti_UpperSat_m5funkuur3
	  section.data(132).logicalSrcIdx = 133;
	  section.data(132).dtTransOffset = 7693;
	
	  ;% rtP.inti_LowerSat_hwyc0llog5
	  section.data(133).logicalSrcIdx = 134;
	  section.data(133).dtTransOffset = 7694;
	
	  ;% rtP.Gain_Gain_f4berbk0ip
	  section.data(134).logicalSrcIdx = 135;
	  section.data(134).dtTransOffset = 7695;
	
	  ;% rtP.Constant9_Value_e4pjobvupn
	  section.data(135).logicalSrcIdx = 136;
	  section.data(135).dtTransOffset = 7696;
	
	  ;% rtP.StateSpace_A_aeig1o2grk
	  section.data(136).logicalSrcIdx = 137;
	  section.data(136).dtTransOffset = 7697;
	
	  ;% rtP.StateSpace_B_ggzos4rhxs
	  section.data(137).logicalSrcIdx = 138;
	  section.data(137).dtTransOffset = 7698;
	
	  ;% rtP.StateSpace_C_flmaxlhzmm
	  section.data(138).logicalSrcIdx = 139;
	  section.data(138).dtTransOffset = 7699;
	
	  ;% rtP.StateSpace_X0_fdo1l0da13
	  section.data(139).logicalSrcIdx = 140;
	  section.data(139).dtTransOffset = 7700;
	
	  ;% rtP.Constant5_Value_mdyfw3r2se
	  section.data(140).logicalSrcIdx = 141;
	  section.data(140).dtTransOffset = 7701;
	
	  ;% rtP.Constant4_Value_hx5xprji3v
	  section.data(141).logicalSrcIdx = 142;
	  section.data(141).dtTransOffset = 7702;
	
	  ;% rtP.Switch_Threshold_c01jx1rxkb
	  section.data(142).logicalSrcIdx = 143;
	  section.data(142).dtTransOffset = 7703;
	
	  ;% rtP.Constant4_Value_nfrrjffypp
	  section.data(143).logicalSrcIdx = 144;
	  section.data(143).dtTransOffset = 7704;
	
	  ;% rtP.R3_Gain_h2tjvli4op
	  section.data(144).logicalSrcIdx = 145;
	  section.data(144).dtTransOffset = 7705;
	
	  ;% rtP.Constant_Value_i12rhgm4ll
	  section.data(145).logicalSrcIdx = 146;
	  section.data(145).dtTransOffset = 7706;
	
	  ;% rtP.Constant1_Value_a1rhrhkbfn
	  section.data(146).logicalSrcIdx = 147;
	  section.data(146).dtTransOffset = 7707;
	
	  ;% rtP.Constant3_Value_cy3b2kpr1c
	  section.data(147).logicalSrcIdx = 148;
	  section.data(147).dtTransOffset = 7708;
	
	  ;% rtP.Constant2_Value_a5vfpd3gf4
	  section.data(148).logicalSrcIdx = 149;
	  section.data(148).dtTransOffset = 7709;
	
	  ;% rtP.Constant14_Value_badjrarjmp
	  section.data(149).logicalSrcIdx = 150;
	  section.data(149).dtTransOffset = 7710;
	
	  ;% rtP.Constant15_Value_crqj5fw4c3
	  section.data(150).logicalSrcIdx = 151;
	  section.data(150).dtTransOffset = 7711;
	
	  ;% rtP.Constant16_Value_idauo5rtab
	  section.data(151).logicalSrcIdx = 152;
	  section.data(151).dtTransOffset = 7712;
	
	  ;% rtP.Switch6_Threshold_jp4ffub4pb
	  section.data(152).logicalSrcIdx = 153;
	  section.data(152).dtTransOffset = 7713;
	
	  ;% rtP.Currentfilter1_A_a05epnrbo3
	  section.data(153).logicalSrcIdx = 154;
	  section.data(153).dtTransOffset = 7714;
	
	  ;% rtP.Currentfilter1_C_nx2vxymlgz
	  section.data(154).logicalSrcIdx = 155;
	  section.data(154).dtTransOffset = 7715;
	
	  ;% rtP.Constant7_Value_fs50zyrehf
	  section.data(155).logicalSrcIdx = 156;
	  section.data(155).dtTransOffset = 7716;
	
	  ;% rtP.Constant6_Value_kkiebpd3zp
	  section.data(156).logicalSrcIdx = 157;
	  section.data(156).dtTransOffset = 7717;
	
	  ;% rtP.Switch2_Threshold_dcfkmijqkz
	  section.data(157).logicalSrcIdx = 158;
	  section.data(157).dtTransOffset = 7718;
	
	  ;% rtP.Constant3_Value_jbt5o32vyc
	  section.data(158).logicalSrcIdx = 159;
	  section.data(158).dtTransOffset = 7719;
	
	  ;% rtP.Constant2_Value_idziu2npmy
	  section.data(159).logicalSrcIdx = 160;
	  section.data(159).dtTransOffset = 7720;
	
	  ;% rtP.Switch1_Threshold_id0sltlw43
	  section.data(160).logicalSrcIdx = 161;
	  section.data(160).dtTransOffset = 7721;
	
	  ;% rtP.R1_Gain_lxoje1sbcn
	  section.data(161).logicalSrcIdx = 162;
	  section.data(161).dtTransOffset = 7722;
	
	  ;% rtP.StateSpace_P1_Size_j1wqbrx4kb
	  section.data(162).logicalSrcIdx = 163;
	  section.data(162).dtTransOffset = 7723;
	
	  ;% rtP.StateSpace_P1_gcbokynfeb
	  section.data(163).logicalSrcIdx = 164;
	  section.data(163).dtTransOffset = 7725;
	
	  ;% rtP.StateSpace_P2_Size_ilvhkduu3r
	  section.data(164).logicalSrcIdx = 165;
	  section.data(164).dtTransOffset = 7728;
	
	  ;% rtP.StateSpace_P2_jtefz4j2hs
	  section.data(165).logicalSrcIdx = 166;
	  section.data(165).dtTransOffset = 7730;
	
	  ;% rtP.StateSpace_P3_Size_mtz3nb2eku
	  section.data(166).logicalSrcIdx = 167;
	  section.data(166).dtTransOffset = 7734;
	
	  ;% rtP.StateSpace_P4_Size_fdb0ovkp3r
	  section.data(167).logicalSrcIdx = 169;
	  section.data(167).dtTransOffset = 7736;
	
	  ;% rtP.StateSpace_P4_jnl2tr4gcu
	  section.data(168).logicalSrcIdx = 170;
	  section.data(168).dtTransOffset = 7738;
	
	  ;% rtP.donotdeletethisgain_Gain_cnrap2hfmr
	  section.data(169).logicalSrcIdx = 171;
	  section.data(169).dtTransOffset = 7921;
	
	  ;% rtP.R_Gain_gmkimg2vno
	  section.data(170).logicalSrcIdx = 172;
	  section.data(170).dtTransOffset = 7922;
	
	  ;% rtP.R4_Gain_grw2mkmlr5
	  section.data(171).logicalSrcIdx = 173;
	  section.data(171).dtTransOffset = 7923;
	
	  ;% rtP.Saturation_UpperSat_mo1jv0phgx
	  section.data(172).logicalSrcIdx = 174;
	  section.data(172).dtTransOffset = 7924;
	
	  ;% rtP.Saturation_LowerSat_dggvwabw03
	  section.data(173).logicalSrcIdx = 175;
	  section.data(173).dtTransOffset = 7925;
	
	  ;% rtP.u_Value
	  section.data(174).logicalSrcIdx = 176;
	  section.data(174).dtTransOffset = 7926;
	
	  ;% rtP.Constant11_Value
	  section.data(175).logicalSrcIdx = 177;
	  section.data(175).dtTransOffset = 7927;
	
	  ;% rtP.Constant12_Value
	  section.data(176).logicalSrcIdx = 178;
	  section.data(176).dtTransOffset = 7928;
	
	  ;% rtP.Constant8_Value
	  section.data(177).logicalSrcIdx = 179;
	  section.data(177).dtTransOffset = 7929;
	
	  ;% rtP.Constant_Value_blwrb2w0qh
	  section.data(178).logicalSrcIdx = 180;
	  section.data(178).dtTransOffset = 7930;
	
	  ;% rtP.Gain4_Gain
	  section.data(179).logicalSrcIdx = 181;
	  section.data(179).dtTransOffset = 7931;
	
	  ;% rtP.Gain1_Gain
	  section.data(180).logicalSrcIdx = 182;
	  section.data(180).dtTransOffset = 7932;
	
	  ;% rtP.Ta_Value
	  section.data(181).logicalSrcIdx = 183;
	  section.data(181).dtTransOffset = 7933;
	
	  ;% rtP.Gain2_Gain
	  section.data(182).logicalSrcIdx = 184;
	  section.data(182).dtTransOffset = 7934;
	
	  ;% rtP.Constant_Value_dn32sdoil4
	  section.data(183).logicalSrcIdx = 185;
	  section.data(183).dtTransOffset = 7935;
	
	  ;% rtP.Gain_Gain_dwzn0ogzht
	  section.data(184).logicalSrcIdx = 186;
	  section.data(184).dtTransOffset = 7936;
	
	  ;% rtP.Saturation2_UpperSat
	  section.data(185).logicalSrcIdx = 187;
	  section.data(185).dtTransOffset = 7937;
	
	  ;% rtP.Saturation2_LowerSat
	  section.data(186).logicalSrcIdx = 188;
	  section.data(186).dtTransOffset = 7938;
	
	  ;% rtP.Switch4_Threshold
	  section.data(187).logicalSrcIdx = 189;
	  section.data(187).dtTransOffset = 7939;
	
	  ;% rtP.TransferFcn1_A
	  section.data(188).logicalSrcIdx = 190;
	  section.data(188).dtTransOffset = 7940;
	
	  ;% rtP.TransferFcn1_C
	  section.data(189).logicalSrcIdx = 191;
	  section.data(189).dtTransOffset = 7941;
	
	  ;% rtP.Gain_Gain_npmm5mmnhb
	  section.data(190).logicalSrcIdx = 192;
	  section.data(190).dtTransOffset = 7942;
	
	  ;% rtP.Constant11_Value_fwpcd5xjtn
	  section.data(191).logicalSrcIdx = 193;
	  section.data(191).dtTransOffset = 7943;
	
	  ;% rtP.Constant12_Value_ir3wdqdic4
	  section.data(192).logicalSrcIdx = 194;
	  section.data(192).dtTransOffset = 7944;
	
	  ;% rtP.Constant8_Value_kzavomyluf
	  section.data(193).logicalSrcIdx = 195;
	  section.data(193).dtTransOffset = 7945;
	
	  ;% rtP.Constant_Value_mexjddav50
	  section.data(194).logicalSrcIdx = 196;
	  section.data(194).dtTransOffset = 7946;
	
	  ;% rtP.Gain4_Gain_l2e2nzph1g
	  section.data(195).logicalSrcIdx = 197;
	  section.data(195).dtTransOffset = 7947;
	
	  ;% rtP.Gain1_Gain_fytmd1ajrp
	  section.data(196).logicalSrcIdx = 198;
	  section.data(196).dtTransOffset = 7948;
	
	  ;% rtP.Ta_Value_grpxumhhux
	  section.data(197).logicalSrcIdx = 199;
	  section.data(197).dtTransOffset = 7949;
	
	  ;% rtP.Gain2_Gain_b1lukokzr1
	  section.data(198).logicalSrcIdx = 200;
	  section.data(198).dtTransOffset = 7950;
	
	  ;% rtP.Constant_Value_ce0ilwr0v4
	  section.data(199).logicalSrcIdx = 201;
	  section.data(199).dtTransOffset = 7951;
	
	  ;% rtP.Gain_Gain_mavdcgl3fv
	  section.data(200).logicalSrcIdx = 202;
	  section.data(200).dtTransOffset = 7952;
	
	  ;% rtP.Saturation2_UpperSat_ppqdia3avp
	  section.data(201).logicalSrcIdx = 203;
	  section.data(201).dtTransOffset = 7953;
	
	  ;% rtP.Saturation2_LowerSat_jhnens0jar
	  section.data(202).logicalSrcIdx = 204;
	  section.data(202).dtTransOffset = 7954;
	
	  ;% rtP.Switch4_Threshold_laodusaory
	  section.data(203).logicalSrcIdx = 205;
	  section.data(203).dtTransOffset = 7955;
	
	  ;% rtP.TransferFcn1_A_a3pzcnto0r
	  section.data(204).logicalSrcIdx = 206;
	  section.data(204).dtTransOffset = 7956;
	
	  ;% rtP.TransferFcn1_C_nct1hyfwyw
	  section.data(205).logicalSrcIdx = 207;
	  section.data(205).dtTransOffset = 7957;
	
	  ;% rtP.Gain_Gain_ocmxl2t2zp
	  section.data(206).logicalSrcIdx = 208;
	  section.data(206).dtTransOffset = 7958;
	
	  ;% rtP.Constant11_Value_k5i3bqlkzv
	  section.data(207).logicalSrcIdx = 209;
	  section.data(207).dtTransOffset = 7959;
	
	  ;% rtP.Constant12_Value_ooh2hzd22c
	  section.data(208).logicalSrcIdx = 210;
	  section.data(208).dtTransOffset = 7960;
	
	  ;% rtP.Constant8_Value_ojzmwgq5pn
	  section.data(209).logicalSrcIdx = 211;
	  section.data(209).dtTransOffset = 7961;
	
	  ;% rtP.Constant_Value_fk15mpo45m
	  section.data(210).logicalSrcIdx = 212;
	  section.data(210).dtTransOffset = 7962;
	
	  ;% rtP.Gain4_Gain_bwxmd45ipv
	  section.data(211).logicalSrcIdx = 213;
	  section.data(211).dtTransOffset = 7963;
	
	  ;% rtP.Gain1_Gain_pji14mxcuf
	  section.data(212).logicalSrcIdx = 214;
	  section.data(212).dtTransOffset = 7964;
	
	  ;% rtP.Ta_Value_ko1cwv42q0
	  section.data(213).logicalSrcIdx = 215;
	  section.data(213).dtTransOffset = 7965;
	
	  ;% rtP.Gain2_Gain_oxevkaekqr
	  section.data(214).logicalSrcIdx = 216;
	  section.data(214).dtTransOffset = 7966;
	
	  ;% rtP.Constant_Value_cvgmtz023a
	  section.data(215).logicalSrcIdx = 217;
	  section.data(215).dtTransOffset = 7967;
	
	  ;% rtP.Gain_Gain_ig2ewsw3sm
	  section.data(216).logicalSrcIdx = 218;
	  section.data(216).dtTransOffset = 7968;
	
	  ;% rtP.Saturation2_UpperSat_kllm5hrnuw
	  section.data(217).logicalSrcIdx = 219;
	  section.data(217).dtTransOffset = 7969;
	
	  ;% rtP.Saturation2_LowerSat_lf1dgltu2n
	  section.data(218).logicalSrcIdx = 220;
	  section.data(218).dtTransOffset = 7970;
	
	  ;% rtP.Switch4_Threshold_abb0upiodf
	  section.data(219).logicalSrcIdx = 221;
	  section.data(219).dtTransOffset = 7971;
	
	  ;% rtP.TransferFcn1_A_izgygp24sn
	  section.data(220).logicalSrcIdx = 222;
	  section.data(220).dtTransOffset = 7972;
	
	  ;% rtP.TransferFcn1_C_omqc4vdzkc
	  section.data(221).logicalSrcIdx = 223;
	  section.data(221).dtTransOffset = 7973;
	
	  ;% rtP.Gain_Gain_k3wfy1rzcq
	  section.data(222).logicalSrcIdx = 224;
	  section.data(222).dtTransOffset = 7974;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 179;
      section.data(179)  = dumData; %prealloc
      
	  ;% rtB.jru2iqrfmm
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.gu5rsica4y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.eafza0ignh
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.mo0fhfwjbn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.hbrgffmmwb
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.ffdlej0esm
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.iu235cbed5
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.jm35sgpar2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.o4aync4hqi
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.a4eiiet2o0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.p4h4wunzca
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.lpwludxfnb
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.pmxqn1j2n3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.mfjtrcfybp
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.djwy2mdgcr
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.bn5kz230z1
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.ksvnvluruk
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.b4dvnbx2z0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.losq44zfsw
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.ia1kg5fvtb
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtB.on5jb3go3s
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtB.fgkxbpykg1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtB.cb1nnepflz
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtB.msdjbx4ftv
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtB.kypwxy50kw
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtB.bb25sco2fm
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtB.abmbri4rct
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtB.gi1zeejtvl
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtB.brqcacx4dy
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtB.mzsf40mopc
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtB.ltqlujcfbs
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtB.ml5sunf4wl
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtB.kgwpzskznu
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtB.cu3rpzq1ir
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtB.ebzvvcw0uj
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtB.nvl5qjckkv
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtB.p4pflkgeyq
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtB.ded05j4tle
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtB.kjbniesfcu
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtB.kcia4oomek
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtB.f3yztw02af
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtB.ebadym5xni
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtB.ascuylmfea
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtB.lgl3sevxjx
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtB.i2cij1nsan
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtB.cy2mdsactk
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtB.hrgapvp0ps
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtB.gx3vfbmrpy
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtB.opjh3hy4jh
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtB.dltlpyqxxt
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtB.hesfhsyv0h
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtB.dz2enm0ww0
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtB.j5n5fyudax
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtB.iirqhbasaw
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtB.poiu0irxc0
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtB.fzd1h5apha
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtB.m12jzkvpeg
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtB.nwx1m5flyz
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtB.gre3fyyedb
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtB.ei5r5a5pav
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% rtB.ommpg3cgpv
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% rtB.i1k1tidl2o
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% rtB.olb0grj3j3
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% rtB.mkgovfegci
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% rtB.dfjf12bep4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% rtB.oben2eao5k
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% rtB.btbyo2vcmz
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% rtB.mqfk5v4diy
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% rtB.bfx2u5xgpq
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% rtB.bybpkn3fg3
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% rtB.gqdjkmiehk
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% rtB.mfmapc1zif
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% rtB.m4i5mlkre0
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% rtB.ik21zuu0w2
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% rtB.jqky25xmle
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% rtB.fmkuq1m3bb
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% rtB.brt0odp1ig
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% rtB.hwk4furfbr
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% rtB.poeuuptz0e
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% rtB.kyxi4xk5b1
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% rtB.lad2rbhq0d
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% rtB.n0ykw2xnss
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% rtB.j2m1rxr1a0
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% rtB.nisapdp2vu
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% rtB.dgq5far14c
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% rtB.mdkcdrc1dj
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% rtB.g3fahebeoh
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% rtB.dg1ivic2cv
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% rtB.o2w0cdwc0f
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% rtB.foxxmgfp1n
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% rtB.guy2kz5ncd
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% rtB.fzutsooicn
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% rtB.i0dlbs1b2l
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% rtB.ffql2fnkid
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% rtB.bzhvuobncb
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% rtB.g4hw1qgbdv
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% rtB.prq1vlt5vx
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% rtB.ecaohy0st5
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% rtB.b4dywjx5hn
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% rtB.offgvp1su2
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% rtB.mj03tas4fg
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% rtB.aepfzat2ah
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% rtB.bb0v5z1gyy
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
	  ;% rtB.awto1smfy3
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 103;
	
	  ;% rtB.adxkajg20f
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 104;
	
	  ;% rtB.p5iut1x42c
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 105;
	
	  ;% rtB.bb0be3gnia
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 106;
	
	  ;% rtB.hqpcpdn5qa
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 107;
	
	  ;% rtB.jbhxgjw5cy
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 108;
	
	  ;% rtB.nf3rdcvax5
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 109;
	
	  ;% rtB.j4gfvflild
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 110;
	
	  ;% rtB.lzetnopoo3
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 111;
	
	  ;% rtB.jce4jecbbp
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 112;
	
	  ;% rtB.dwb42stmvv
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 113;
	
	  ;% rtB.gu3qbji4xc
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 114;
	
	  ;% rtB.pgudi1oete
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 115;
	
	  ;% rtB.fmw5kmtm1r
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 116;
	
	  ;% rtB.bwvje3ihiw
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 117;
	
	  ;% rtB.m0yglvlyme
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 118;
	
	  ;% rtB.pvwijbyxkr
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 119;
	
	  ;% rtB.aesu3l5yyk
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 120;
	
	  ;% rtB.e3cqouyy3w
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 121;
	
	  ;% rtB.dcqdhsbevr
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 122;
	
	  ;% rtB.o3lepigeif
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 123;
	
	  ;% rtB.d5351zjf4x
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 124;
	
	  ;% rtB.eoju45gqpq
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 125;
	
	  ;% rtB.dfbrmr4pqz
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 126;
	
	  ;% rtB.dabeiiy4xg
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 127;
	
	  ;% rtB.koz3cqzv1c
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 128;
	
	  ;% rtB.etpdoa2xuk
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 129;
	
	  ;% rtB.jaquvxw41i
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 130;
	
	  ;% rtB.oaqch21uel
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 131;
	
	  ;% rtB.lvkqstzrdf
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 132;
	
	  ;% rtB.lmk5yid3hu
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 133;
	
	  ;% rtB.grozn2da0l
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 134;
	
	  ;% rtB.dzqkvxhkd1
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 135;
	
	  ;% rtB.n5c0k4fbwb
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 136;
	
	  ;% rtB.lwlovbyzf2
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 137;
	
	  ;% rtB.n0r3f03erl
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 138;
	
	  ;% rtB.e0dl0dglhu
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 139;
	
	  ;% rtB.j3xdv1bkdg
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 140;
	
	  ;% rtB.maqw5opry0
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 141;
	
	  ;% rtB.acjy0wcx33
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 142;
	
	  ;% rtB.ffgdskx2hu
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 143;
	
	  ;% rtB.brdas51kj1
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 144;
	
	  ;% rtB.nfweyj1qvq
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 145;
	
	  ;% rtB.h2cdsbamjg
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 146;
	
	  ;% rtB.njpjxwiwga
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 147;
	
	  ;% rtB.mc3kmonqyw
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 148;
	
	  ;% rtB.eajyu4e2gg
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 149;
	
	  ;% rtB.csv1q2rmqm
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 150;
	
	  ;% rtB.hap1ivasmg
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 151;
	
	  ;% rtB.o0zujw030w
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 152;
	
	  ;% rtB.hrenjgvsp2
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 153;
	
	  ;% rtB.agnwtijpiy
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 154;
	
	  ;% rtB.oepc1i4s5o
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 155;
	
	  ;% rtB.gnxuzeutps
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 156;
	
	  ;% rtB.hoa4ffors0
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 157;
	
	  ;% rtB.p5bxowhy3u
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 158;
	
	  ;% rtB.dl2oj2hwn5
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 159;
	
	  ;% rtB.btonwzxytu
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 160;
	
	  ;% rtB.g03b5ho0xb
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 161;
	
	  ;% rtB.egi1glv2iz
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 165;
	
	  ;% rtB.aufyna3xwp
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 169;
	
	  ;% rtB.dpzsk0fv2e
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 173;
	
	  ;% rtB.oiiyyqltbq
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 177;
	
	  ;% rtB.pjy23u5hnz
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 178;
	
	  ;% rtB.b3jprbo2ch
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 179;
	
	  ;% rtB.psc1bdwm0e
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 180;
	
	  ;% rtB.lwryrfr1np
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 184;
	
	  ;% rtB.dehp52jxod
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 188;
	
	  ;% rtB.dhz0gnwoz2
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 192;
	
	  ;% rtB.chxlnefiu2
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 196;
	
	  ;% rtB.gucbgg34uu
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 197;
	
	  ;% rtB.jl0as1i1kv
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 198;
	
	  ;% rtB.gayccjz0g2
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 199;
	
	  ;% rtB.cgcsvraqod
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 203;
	
	  ;% rtB.amabyxe2q5
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 207;
	
	  ;% rtB.hp4pbsppeu
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 211;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% rtB.p3hqh0p1ve
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.gibfnm5yif
	  section.data(2).logicalSrcIdx = 180;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.h5yixci3b5
	  section.data(3).logicalSrcIdx = 181;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.iu45wsrpul
	  section.data(4).logicalSrcIdx = 182;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.l5k4v4pkri
	  section.data(5).logicalSrcIdx = 183;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.bbvpjaqjcj
	  section.data(6).logicalSrcIdx = 184;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.c33k25rpdh
	  section.data(7).logicalSrcIdx = 185;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.pm3wjc2bv1
	  section.data(8).logicalSrcIdx = 186;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.kvprg4ppnw
	  section.data(9).logicalSrcIdx = 187;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.eqm015gtbx
	  section.data(10).logicalSrcIdx = 188;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.hvjsipjvee
	  section.data(11).logicalSrcIdx = 189;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.nj4n1mxjv0
	  section.data(12).logicalSrcIdx = 190;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.druqytbldp
	  section.data(13).logicalSrcIdx = 191;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.kjxguscvc3
	  section.data(14).logicalSrcIdx = 192;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.f142q2bocw
	  section.data(15).logicalSrcIdx = 193;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.b1tb4rlksj
	  section.data(16).logicalSrcIdx = 194;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.ewa4jwoiei
	  section.data(17).logicalSrcIdx = 195;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.h54wfmqlk0
	  section.data(18).logicalSrcIdx = 196;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.jflxrokyki
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gkgewmrthj
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.byrrqwbwuv
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ko2pp0cfqy
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.knyijtosqg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ft2nyeqcg1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.my4ttjz2fk
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.an5tlpibsu
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtDW.cnb4tdv1fb
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.ixzxf22pdy.TimePtr
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.i52v1nqs1o
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ifo13hvcar.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 23;
	
	  ;% rtDW.pasjhbqynx
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 26;
	
	  ;% rtDW.dyo1jajuwp.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 48;
	
	  ;% rtDW.cxgfidnvpg
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 51;
	
	  ;% rtDW.chubbvu0th.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 73;
	
	  ;% rtDW.cddwntinmn.LoggedData
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 76;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% rtDW.nkl51yszn4
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.j4pqvee5xt.PrevIndex
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.i3jqpyztxw
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.fyfdvnwnzj
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 25;
	
	  ;% rtDW.cdm1crpp3z
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 26;
	
	  ;% rtDW.gxhjb1iyjf
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 49;
	
	  ;% rtDW.efvfgmr2jk
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 50;
	
	  ;% rtDW.j4qnczxkrf
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 73;
	
	  ;% rtDW.ezytuzrwcm
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 74;
	
	  ;% rtDW.cr3vas1c0t
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 75;
	
	  ;% rtDW.i5fsfrib41
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 76;
	
	  ;% rtDW.l4pyajhrvl
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 77;
	
	  ;% rtDW.etgutsyzrf
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 78;
	
	  ;% rtDW.nn2v3m5mqb
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 79;
	
	  ;% rtDW.i4dp0latxw
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 80;
	
	  ;% rtDW.elzvn2clyn
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 81;
	
	  ;% rtDW.p4ho05td4b
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 82;
	
	  ;% rtDW.okerpy1dzv
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 83;
	
	  ;% rtDW.ayr4ahfun4
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 84;
	
	  ;% rtDW.j220vn1p2t
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 85;
	
	  ;% rtDW.e0tyil0jmq
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 86;
	
	  ;% rtDW.llbft42mya
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 87;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% rtDW.e2bbi1copd
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.aroxcxqsxi
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.cgagzvjehp
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.nsqv1bhvah
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.oajahukjrq
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.jq3tf3x1xs
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.hvbgl0hgfc
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.dvabjhaxc1
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.i3xk5pcc1t
	  section.data(9).logicalSrcIdx = 47;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.okwoxppsxh
	  section.data(10).logicalSrcIdx = 48;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.erby3qbuzu
	  section.data(11).logicalSrcIdx = 49;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.knppb5aj2r
	  section.data(12).logicalSrcIdx = 50;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ecnrycha4x
	  section.data(13).logicalSrcIdx = 51;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.dkqm0duv1u
	  section.data(14).logicalSrcIdx = 52;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.f4ellfbxmn
	  section.data(15).logicalSrcIdx = 53;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.guk1qwasso
	  section.data(16).logicalSrcIdx = 54;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.d3wwahyjdv
	  section.data(17).logicalSrcIdx = 55;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.bwnvfnkkdo
	  section.data(18).logicalSrcIdx = 56;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.gurrglctsf
	  section.data(19).logicalSrcIdx = 57;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.nrqdnhqrpx
	  section.data(20).logicalSrcIdx = 58;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.i0tbjbubdb
	  section.data(21).logicalSrcIdx = 59;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.ho5g2sdnaf
	  section.data(22).logicalSrcIdx = 60;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.ixmlzcolrr
	  section.data(23).logicalSrcIdx = 61;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.fkqektwhpq
	  section.data(24).logicalSrcIdx = 62;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.ieybpiozzj
	  section.data(25).logicalSrcIdx = 63;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.e4tlndddzv
	  section.data(26).logicalSrcIdx = 64;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.abjaxhp14q
	  section.data(27).logicalSrcIdx = 65;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.ivlzoptp2y
	  section.data(28).logicalSrcIdx = 66;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.bkvk3xox1d
	  section.data(29).logicalSrcIdx = 67;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.mwafatbfsb
	  section.data(30).logicalSrcIdx = 68;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 562528118;
  targMap.checksum1 = 4015142401;
  targMap.checksum2 = 125993725;
  targMap.checksum3 = 1970498346;

