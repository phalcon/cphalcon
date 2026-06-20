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

namespace Phalcon\Tests;

use Phalcon\DataMapper\Statement\Bind;
use ReflectionClass;

abstract class AbstractStatementTestCase extends AbstractDatabaseTestCase
{
    /**
     * @return void
     */
    protected function setUp(): void
    {
        /**
         * This is here to ensure that the tests run fine either individually
         * or as a suite, since the static instance count will increase
         * differently depending on how the test is run (suite/on its own)
         */
        parent::setUp();

        $bind = new ReflectionClass(Bind::class);
        $property = $bind->getProperty('instanceCount');
        $property->setValue(0);
    }
}
