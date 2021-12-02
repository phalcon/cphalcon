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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\ValidatorCompositeInterface;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorStringLengthConstruct(IntegrationTester $I)
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
