<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\ValidatorFactory;

use Phalcon\Validation\Validator\Alnum;
use Phalcon\Validation\ValidatorFactory;
use IntegrationTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Validation\ValidatorFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function imageValidatorFactoryNewInstance(IntegrationTester $I)
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
