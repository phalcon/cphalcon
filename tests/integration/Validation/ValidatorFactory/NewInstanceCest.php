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

namespace Phalcon\Tests\Integration\Validation\ValidatorFactory;

use IntegrationTester;
use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\ValidatorFactory;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Filter\Validation\ValidatorFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function filterValidationValidatorFactoryNewInstance(IntegrationTester $I)
    {
        $I->wantToTest('Validation\ValidatorFactory - newInstance()');

        $factory = new ValidatorFactory();
        $name    = 'alnum';

        $validator = $factory->newInstance($name);

        $I->assertInstanceOf(
            Alnum::class,
            $validator
        );
    }
}
