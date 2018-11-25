<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\Url;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\Url;
use UnitTester;

class GetOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\Url :: getOption()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorUrlGetOption(UnitTester $I)
    {
        $validator = new Url();
        $this->checkGetOption($I, $validator);
    }
}
