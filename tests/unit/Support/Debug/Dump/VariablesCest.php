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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use stdClass;
use UnitTester;

use function dataDir;
use function file_get_contents;

class VariablesCest
{
    /**
     * Tests Phalcon\Debug\Dump :: variables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugDumpVariables(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variables()');

        $test1 = 'string';
        $test2 = ['key' => 'value'];
        $test3 = new stdClass();

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Dump/variables_output.txt')
            )
        );

        $actual = $dump->variables($test1, $test2, $test3);
        if (PHP_OS === 'Windows') {
            $actual = str_replace('\n', PHP_EOL, $actual);
        }
        $I->assertEquals($expected, $actual);
    }
}
