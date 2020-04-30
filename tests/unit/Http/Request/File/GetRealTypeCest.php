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

namespace Phalcon\Test\Unit\Http\Request\File;

use Phalcon\Http\Request\File;
use UnitTester;

use function dataDir;
use function function_exists;

class GetRealTypeCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getRealType()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1442
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-26
     */
    public function httpRequestFileGetRealType(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getRealType()');

        if (!function_exists('finfo_open')) {
            $I->skipTest('fileinfo extension missing');
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

        $I->assertEquals('image/jpeg', $file->getRealType());
    }
}
