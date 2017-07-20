<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File;

/**
 * \Phalcon\Test\Unit\Validation\Validator\FileTest
 * Tests the \Phalcon\Validation\Validator\File component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
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
     * Tests file validator with single field
     *
     * @author Mateusz Blaszczyk
     * @since  2017-07-20
     */
    public function testSingleField()
    {
        $this->specify(
            'Test file validator.',
            function () {
                $validation = new Validation();

                $validation->add('file', new File([
                    'minSize' => '1B',
                    'maxSize' => '1M',
                    'messageSize' => 'Field file must be an smaller than 1MB',
                    'allowedTypes' => ['image/jpeg', 'image/pjpeg', 'image/png'],
                    'messageType' => 'Allowed file types are: JPG, JPEG and PNG',
                    'messageEmpty' => 'Field file was not send'
                ]));

                $messages = $validation->validate([
                    'tmp_name' => 'example_tmp_name',
                    'error' => UPLOAD_ERR_OK,
                    'size' => 1024 * 1024
                ]);
                expect($messages->count())->equals(0);

                $messages = $validation->validate([
                    'tmp_name' => 'example_tmp_name',
                    'error' => UPLOAD_ERR_OK,
                    'size' => (1024 * 1024) + 1
                ]);
                expect($messages->count())->equals(1);
/*
                $messages = $validation->validate(['email' => 'rootlocalhost']);
                expect($messages->count())->equals(1);*/

                /*$expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'File',
                                    '_message' => 'Field file must be an smaller than 1MB',
                                    '_field'   => 'file',
                                    '_code'    => 0,
                                ]
                            )
                        ]
                    ]
                );

                expect($expectedMessages)->equals($messages);*/
            }
        );
    }


}
