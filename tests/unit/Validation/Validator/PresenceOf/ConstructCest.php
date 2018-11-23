<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\PresenceOf;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\ValidatorInterface;
use UnitTester;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\PresenceOf :: getOption()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorPresenceOfConstruct(UnitTester $I)
    {
        $validator = new PresenceOf();
        $I->assertInstanceOf(ValidatorInterface::class, $validator);
    }
}
