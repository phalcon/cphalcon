<?php

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request\File;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Http\Request\FileFileTest
 * Tests the \Phalcon\Http\Request\File component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Http\Request
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FileTest extends UnitTest
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
