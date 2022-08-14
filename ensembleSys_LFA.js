// // SetUp //
// autowatch = 1;
// outlets = 3;

// // GloabVariables // 
// var chordProg = 0; 

// // Notes // 
// var sG3 = 207.65;
// var A3 = 220;
// var sA3 = 233.08;
// var B3 = 246.94;
// var C4 = 261.63;
// var sC4 = 277.18;
// var D4 = 293.66;
// var sD4 = 311.13;
// var E4 = 329.63;
// var F4 = 349.23;
// var sF4 = 369.99;
// var G4 = 392;
// var sG4 = 415.3;
// var A4 = 440;
// var sA4 = 466.16; 
// var B4 = 493.88;
// var C5 = 523.25;
// var sC5 = 554.37;
// var D5 = 587.33; 
// var sD5 = 622.25;

// // ChordProg // 
// // [ 
// //     [F4,D4,A3] // 349.23 | 293.66 | 220 || chord 00     
// //         [F4,D4,sA3] // 349.23 | 293.66 | 233.08 || chord 01    
// //             [G4,D4,sA3] // 392 | 293.66 | 233.08 || chord 02
// //                 [G4,D4,C4] // 392 | 293.66 | 261.63 || chord 03
// //                     [G4,E4,C4] // 392 | 329.63 | 261.63 || chord 04
// //                         [A4,E4,C4] // 440 | 329.63 | 261.63 || chord 05
// //                             [A4,E4,D4] // 440 | 329.63 | 293.66 || chord 06
// //                                 [A4,F4,D4] // 440 | 349.23 | 293.66 || chord 07
// //                                     [sA4,F4,D4] // 466.16 | 349.23 | 293.66 || chord 08
// //                                         [sA4,G4,E4] // 466.16 | 392 | 329.63 || chord 09
// //                                             [C5,G4,E4] // 523.25 | 392 | 329.63 || chord 10
// //                                                 [C5,A4,F4] // 523.25 | 440 | 349.23 || chord 11
// // ];


// var userA = [F4,F4,G4,G4,G4,A4,A4,A4,A4,sA4,sA4,C5,C5];
// var userB = [D4,D4,D4,D4,E4,E4,E4,F4,F4,G4,G4,A4];
// var userC = [A3,sA3,sA3,C4,C4,C4,D4,D4,D4,E4,E4,F4];
// var userChord = [userA, userB, userC];
// var counter = 0;
// var chordIndex = 0;

// var alpha_freq = 5;

// // Game System

// function playChord(freqA, freqB, freqC)
// {
//     var result = [false,false,false];

//     if(Math.abs(freqA-userA[chordIndex])<alpha_freq)
//     {
//         ressult[0]=true;
//     }

//     if(Math.abs(freqB-userB[chordIndex])<alpha_freq)
//     {
//         ressult[1]=true;
//     }

//     if(Math.abs(freqC-userC[chordIndex])<alpha_freq)
//     {
//         ressult[2]=true;
//     }

//     // for(var i = 0; i < 3; i++)
//     // {
//     //     // 
//     // }

//     if(result = [true,true,true])
//     {
//         chordIndex++;
//         counter++;
//     }

//     else // if not all of them are on the target
//     {
//         outlet(0,false);
//     }

//     outlet(1, "counting" + counter);
//     outlet(2, "current chord" + chordIndex);
    
// }

// playChord();
