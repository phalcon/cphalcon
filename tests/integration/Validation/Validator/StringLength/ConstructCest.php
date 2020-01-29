<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Validation\Validator\StringLength;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\ValidatorCompositeInterface;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\StringLength :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function validationValidatorStringLengthConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - __construct()');

        $validator = new StringLength();

        $this->checkConstruct($I, $validator);

        $I->assertInstanceOf(
            ValidatorCompositeInterface::class,
            $validator,
            'StringLength implements ValidatorCompositeInterface'
        );
    }
}
