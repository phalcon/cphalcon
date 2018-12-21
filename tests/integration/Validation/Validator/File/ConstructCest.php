<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\File;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\File;
use Phalcon\Validation\ValidatorInterface;
use IntegrationTester;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\File :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorFileConstruct(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\File - __construct()");
        $validator = new File();
        $this->checkConstruct($I, $validator);
    }
}
