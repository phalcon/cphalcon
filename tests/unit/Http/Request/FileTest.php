<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request\File;
use Phalcon\Test\Module\UnitTest;
use UnitTester;

class FileTest
{
    /**
     * Tests getRealType
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/1442
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-26
     */
    public function testRealType()
    {
        if (!extension_loaded('fileinfo')) {
            $this->markTestSkipped('Warning: fileinfo extension is not loaded');
        }

        $this->specify(
            "getRealType does not returns real type",
            function () {
                $file = new File([
                    'name'        => 'test',
                    'type'        => 'text/plain',
                    'tmp_name'    => PATH_DATA . '/assets/phalconphp.jpg',
                    'size'        => 1,
                    'error'        => 0,
                ]);

                expect($file->getType())->equals('text/plain');
                expect($file->getRealType())->equals('image/jpeg');
            }
        );
    }
}
