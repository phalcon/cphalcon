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
use Phalcon\Tests\Fixtures\Dump\ClassProperties;
use ReflectionException;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Debug\Dump :: __construct() - dump properties
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13315
     *
     * @throws ReflectionException
     * @since  2014-10-23
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function supportDebugDumpConstructDump(UnitTester $I)
    {
        $I->skipTest("Needs a review");
        $I->wantToTest('Debug\Dump - __construct() - dump properties');

        $patient = new ClassProperties();
        $dump    = new Dump([], true);

        $actual = $I->callProtectedMethod($dump, 'output', $patient);

        $expected = file_get_contents(
            dataDir('fixtures/Dump/class_properties.txt')
        );

        // Test without HTML
        $actual = strip_tags($actual);

        // Remove a trailing newline
        $expected = trim($expected);
        $I->assertEquals($expected, $actual);
    }
}
