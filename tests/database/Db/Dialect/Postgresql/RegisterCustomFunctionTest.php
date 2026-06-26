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

namespace Phalcon\Tests\Database\Db\Dialect\Postgresql;

use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RegisterCustomFunctionTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: registerCustomFunction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbDialectPostgresqlRegisterCustomFunction(): void
    {
        $dialect = new Postgresql();

        $returned = $dialect->registerCustomFunction(
            'MYFUNC',
            function ($dialect, $expression) {
                return 'MYFUNC()';
            }
        );

        $this->assertSame($dialect, $returned);

        $functions = $dialect->getCustomFunctions();

        $this->assertArrayHasKey('MYFUNC', $functions);
        $this->assertIsCallable($functions['MYFUNC']);
    }
}
