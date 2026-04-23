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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Filter\FilterInterface;
use Phalcon\Filter\Validation;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function testFilterValidationUnderscoreGet(): void
    {
        FactoryDefault::reset();
        $container = new FactoryDefault();
        FactoryDefault::setDefault($container);

        $validation = new Validation();

        // Accessing a registered DI service returns its instance
        $filter = $validation->filter;
        $this->assertInstanceOf(FilterInterface::class, $filter);

        // Accessing 'di' returns the container itself
        $di = $validation->di;
        $this->assertInstanceOf(Di::class, $di);
    }
}
