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

/**
 * Class VariablesCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class VariablesCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: variables()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpVariables(UnitTester $I)
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $I->wantToTest('Debug\Dump - variables()');

        $test1 = 'string';
        $test2 = ['key' => 'value'];
        $test3 = new stdClass();

        $dump = new Dump();

        $expected = trim(
            file_get_contents(
                dataDir('fixtures/Support/Dump/variables_output.txt')
            )
        );
        $actual   = $dump->variables($test1, $test2, $test3);
        $I->assertEquals($expected, $actual);
    }
}
