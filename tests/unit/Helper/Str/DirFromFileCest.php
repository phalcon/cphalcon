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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class DirFromFileCest
 */
class DirFromFileCest
{
    /**
     * Tests Phalcon\Helper\Str :: dirFromFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function helperStrFolderFromFile(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dirFromFile()');
        $fileName = 'abcdef12345.jpg';

        $expected = 'ab/cd/ef/12/3/';
        $actual   = Str::dirFromFile($fileName);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: dirFromFile() - empty string
     *
     * @param UnitTester $I
     */
    public function helperStrFolderFromFileEmptyString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dirFromFile() - empty string');
        $fileName = '';

        $expected = '/';
        $actual   = Str::dirFromFile($fileName);
        $I->assertEquals($expected, $actual);
    }
}
