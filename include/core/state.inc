// Ultima BR
// Author: Fenrir

include ":ai:core/enum";

var aiState := AI_STATE_SLEEP;
var aiStateFunctions := dictionary;
var aiStatesDecorators := array;

/* 
 * Description
 *   Execute state
 *
 * Parameters
 *   state:                 State
 *   func:                  Function object
 */
function AiStateExecute()

    me.SetProp("AiState", aiState);

    AiStateDecorate(aiStatesDecorators.size());

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert state
 *
 * Parameters
 *   state:                 State
 *   func:                  Function object
 */
function AiStateInsert(state, func)

    aiStateFunctions.insert(state, func);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Erase state
 *
 * Parameters
 *   state:                 State
 */
function AiStateErase(state)

    aiStateFunctions.erase(state);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Execute state function
 */
function AiStateExecuteFunction()

    if (!(aiState in aiStateFunctions.keys()))
        return;
    endif

    aiStateFunctions[aiState].call();

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert decorator for state
 *
 * Parameters
 *   func:                  Function object
 */
function AiStateDecorateInsert(func)

    aiStatesDecorators.append(func);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Decorate state
 *
 * Parameters
 *   index:                 Decorator index
 */
function AiStateDecorate(index)

    if (index > 0)
        aiStatesDecorators[index].call(aiStatesDecorators, index);
    else
        AiStateExecuteFunction();
    endif

endfunction