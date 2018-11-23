<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\Callback;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\Callback;
use UnitTester;

class HasOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\Callback :: getOption()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorCallbackHasOption(UnitTester $I)
    {
        $validator = new Callback(['message' => 'This is a message']);
        $this->validatorHasOption($I, $validator);
    }
}
