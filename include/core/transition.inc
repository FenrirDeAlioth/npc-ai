// Ultima BR
// Author: Fenrir

var aiTransitions := dictionary;
var aiTransitionDecorators := array;

/* 
 * Description transition
 *   Execute state transition
 *
 * Parameters
 *   state:                 State
 *   func:                  Function object
 */
function AiTransitionExecute()

    AiTransitionDecorate(aiTransitionDecorators.size());

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert state transition
 *
 * Parameters
 *   state:                 State
 *   func:                  Function object
 *   priority:              Priority
 */
function AiTransitionInsert(state, func, priority)

    if !(state in aiTransitions.keys())
        aiTransitions.insert(state, array);
    endif

    aiTransitions[state].sorted_insert({func, priority}, 2, 1);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Erase state transition
 *
 * Parameters
 *   state:                 State
 *   func:                  Function object
 */
function AiTransitionErase(state, func)

    if !(state in aiTransitions.keys())
        return;
    endif

    foreach transition in (aiTransitions[state])

        if (transition[1] == func)

            aiTransitions[state].erase(_transition_iter);

            if (!aiTransitions[state].size())
                aiTransitions.erase(state);
            endif

        endif

    endforeach

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Execute state transition functions
 */
function AiTransitionExecuteFunction()

    if (!(aiState in aiTransitions.keys()))
        return;
    endif

    foreach transition in (aiTransitions[aiState])

        if (transition[1].call())
            return;
        endif

    endforeach

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert decorator for state transition
 *
 * Parameters
 *   func:                  Function object
 */
function AiTransitionDecorateInsert(func)

    aiTransitionDecorators.append(func);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Decorate state transition
 *
 * Parameters
 *   index:                 Decorator index
 */
function AiTransitionDecorate(index)

    if (index > 0)
        aiTransitionDecorators[index].call(aiTransitionDecorators, index);
    else
        AiTransitionExecuteFunction();
    endif

endfunction