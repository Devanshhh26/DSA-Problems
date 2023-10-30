//  https://leetcode.com/problems/min-stack/description/


// iss question ko hum ek vector array se implement karenge  jo ek pair input legi jisme pehla input hoga curr element aur
// dusra input hoga min element

// for push : agar staack empty hai to dono me val input hoga 
// agar stack empty nahi hai to first me val dalega aur second me compare karenge min val ko curr val se aur unka minimum daaal denge

// for pop: direct pop_back kardenge

// for top  : vector ka last element hi top hoga to vector.back().first

// for minval: minimum value vector ke end me padi hogi islie vecotr.back().second