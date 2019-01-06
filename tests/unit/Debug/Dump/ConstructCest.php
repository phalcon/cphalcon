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

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use Phalcon\Test\Fixtures\Dump\ClassProperties;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Debug\Dump :: __construct() - dump properties
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13315
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-23
     *
     * @throws \ReflectionException
     */
    public function debugDumpConstructDump(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - __construct() - dump properties');
        $patient = new ClassProperties();
        $dump    = new Dump([], true);

        $actual   = $I->callProtectedMethod($dump, 'output', $patient);
        $expected = file_get_contents(dataFolder('fixtures/Dump/class_properties.txt'));

        // Test without HTML
        $actual = strip_tags($actual);

        // Remove a trailing newline
        $expected = trim($expected);
        $I->assertEquals($expected, $actual);
    }
}
