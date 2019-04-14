// Ultima BR
// Author: Fenrir

use util;

AiStateInsert(AI_STATE_SLEEP, @AiSleepState);

/* 
 * Description
 *   Sleep state
 */
function AiSleepState()

    event := Wait_For_Event(RandomIntMinMax(36000, 72000));

endfunction