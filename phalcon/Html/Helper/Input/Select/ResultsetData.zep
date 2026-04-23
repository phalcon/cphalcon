
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input\Select;

use InvalidArgumentException;
use Phalcon\Mvc\Model\ResultsetInterface;

class ResultsetData implements SelectDataInterface
{
    /**
     * @var ResultsetInterface
     */
    protected resultset;

    /**
     * @var array
     */
    protected using = [];

    /**
     * @param ResultsetInterface resultset
     * @param array              using
     */
    public function __construct(<ResultsetInterface> resultset, array using)
    {
        if unlikely count(using) !== 2 {
            throw new InvalidArgumentException(
                "The 'using' parameter requires exactly two values"
            );
        }

        let this->resultset = resultset;
        let this->using     = using;
    }

    /**
     * @return array
     */
    public function getOptions() -> array
    {
        var option, optionText, optionValue, options, usingZero, usingOne;

        let usingZero = this->using[0],
            usingOne  = this->using[1],
            options   = [];

        for option in this->resultset {
            if typeof option == "object" {
                if method_exists(option, "readAttribute") {
                    let optionValue = option->readAttribute(usingZero),
                        optionText  = option->readAttribute(usingOne);
                } else {
                    let optionValue = option->{usingZero},
                        optionText  = option->{usingOne};
                }
            } else {
                if unlikely typeof option != "array" {
                    throw new InvalidArgumentException(
                        "Resultset returned an invalid value"
                    );
                }

                let optionValue = option[usingZero],
                    optionText  = option[usingOne];
            }

            let options[optionValue] = optionText;
        }

        return options;
    }
}
