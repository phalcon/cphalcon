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

namespace Phalcon\Tests\Unit\Filter\Validation\ValidatorFactory;

use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\ValidatorFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function testFilterValidationValidatorFactoryNewInstance(): void
    {
        $factory = new ValidatorFactory();
        $name = 'alnum';

        $validator = $factory->newInstance($name);

        $this->assertInstanceOf(Alnum::class, $validator);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function testFilterValidationValidatorFactoryNewInstanceException(): void
    {
        $factory = new ValidatorFactory();
        $name = 'unknown';

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Service unknown is not registered');

        $factory->newInstance($name);
    }
}
