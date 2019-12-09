<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request\File;
use UnitTester;

use function dataDir;

class FileCest
{
    /**
     * Tests getRealType
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1442
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-26
     */
    public function testRealType(UnitTester $I)
    {
        if (!extension_loaded('fileinfo')) {
            $I->skipTest('Warning: fileinfo extension is not loaded');
        }

        $file = new File(
            [
                'name'     => 'test',
                'type'     => 'text/plain',
                'tmp_name' => dataDir('/assets/images/phalconphp.jpg'),
                'size'     => 1,
                'error'    => 0,
            ]
        );

        $expected = 'text/plain';
        $actual   = $file->getType();
        $I->assertEquals($expected, $actual);

        $expected = 'image/jpeg';
        $actual   = $file->getRealType();
        $I->assertEquals($expected, $actual);
    }
}
