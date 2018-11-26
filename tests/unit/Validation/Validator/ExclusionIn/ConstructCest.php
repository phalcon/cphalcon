<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\ExclusionIn;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\ExclusionIn;
use Phalcon\Validation\ValidatorInterface;
use UnitTester;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\ExclusionIn :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorExclusionInConstruct(UnitTester $I)
    {
        $I->wantToTest("Validation\Validator\ExclusionIn - __construct()");
        $validator = new ExclusionIn();
        $this->checkConstruct($I, $validator);
    }
}
