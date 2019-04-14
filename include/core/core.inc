// Ultima BR
// Author: Fenrir

var me := Self();
var event;

var aiConfigurators := array;
var aiInitializers := array;

/* 
 * Description
 *   Initialize AI
 */
function AiStart()

    if (!me.GetProp("Configured"))

        foreach configurator in (aiConfigurators)
            configurator.call();
        endforeach

    endif

    me.SetProp("Configured", 1);

    foreach initilizer in (aiInitializers)
        initilizer.call();
    endforeach

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert ai configurator
 *
 * Parameters
 *   func:                  Function object
 */
function AiConfiguratorInsert(func)

    aiConfigurators.append(func);

endfunction

// --------------------------------------------------------------------------------------------- //

/* 
 * Description
 *   Insert ai initializer
 *
 * Parameters
 *   func:                  Function object
 */
function AiInitializerInsert(func)

    aiInitializers.append(func);

endfunction