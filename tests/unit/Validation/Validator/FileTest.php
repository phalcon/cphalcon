<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use AspectMock\Test;
use Phalcon\Http\Request;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File;

/**
 * \Phalcon\Test\Unit\Validation\Validator\FileTest
 * Tests the \Phalcon\Validation\Validator\File component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FileTest extends UnitTest
{
    /**
     * @var array
     */
    protected $files;

    /**
     * executed before each test
     */
    public function _before()
    {
        $this->markTestSkipped('Mocking up php functions doesnt work for zephir extensions.');
        $_FILES = [
            'photo' => [
                'name'     => ['f0', 'f1', ['f2', 'f3'], [[[['f4']]]]],
                'type'     => [
                    'text/plain',
                    'text/csv',
                    ['image/png', 'image/jpeg'],
                    [[[['application/octet-stream']]]],
                ],
                'tmp_name' => ['t0', 't1', ['t2', 't3'], [[[['t4']]]]],
                'error'    => [0, 0, [0, 0], [[[[8]]]]],
                'size'     => [10, 20, [30, 40], [[[[50]]]]],
            ],
        ];
        $request = new Request();
        $request->setDI($this->tester->getApplication()->getDI());
        $uploadedFiles = $request->getUploadedFiles();
        $files = [];
        /** @var Request\File $file */
        foreach ($uploadedFiles as $file) {
            $files[] = [
                'name'     => $file->getName(),
                'tmp_name' => $file->getTempName(),
                'type'     => $file->getType(),
                'size'     => $file->getSize(),
                'error'    => $file->getError(),
            ];
        }
        $this->files = $files;
        Test::func(
            'Phalcon\Validation\Validator',
            'getimagesize',
            function ($tmpName) {
                $tmpSizes = [
                    't0' => null,
                    't1' => null,
                    't2' => [500, 500],
                    't3' => [1000, 1000],
                    't4' => null,
                ];

                return $tmpSizes[$tmpName];
            }
        );
        Test::func(
            'Phalcon\Validation\Validator',
            'finfo_open',
            function ($mimeType) {
                return null;
            }
        );
        Test::func(
            'Phalcon\Validation\Validator',
            'finfo_file',
            function ($tmp, $tmpName) {
                $tmpTypes = [
                    't0' => 'text/plain',
                    't1' => 'text/csv',
                    't2' => 'image/png',
                    't3' => 'image/jpeg',
                    't4' => 'application/octet-stream',
                ];

                return $tmpTypes[$tmpName];
            }
        );
        Test::func(
            'Phalcon\Validation\Validator',
            'is_uploaded_file',
            function ($tmpName) {
                return true;
            }
        );
        Test::func(
            'Phalcon\Validation\Validator',
            'finfo_close',
            function ($tmp, $tmpName) {
            }
        );
        $_SERVER["REQUEST_METHOD"] = "POST";
    }

    /**
     * executed after each test
     */
    public function _after()
    {
        Test::clean();
        unset($_SERVER["REQUEST_METHOD"]);
    }

    /**
     * Tests file validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-23
     */
    public function testSingleField()
    {
        $this->specify(
            'The file validator does not validates correctly with single field',
            function () {
                $validation = new Validation();
                $validation->add(
                    'file',
                    new File(
                        [
                            'maxSize'       => '500K',
                            'allowedTypes'  => ['image/jpeg', 'image/png'],
                            'maxResolution' => '800x800',
                            'minResolution' => '1x1',
                            'message'       => 'Image should have max 800x800 resolution',
                        ]
                    )
                );
                $messages = $validation->validate(['file' => $this->files[2]]);
                expect($messages->count())->equals(0);
                $messages = $validation->validate(['file' => $this->files[3]]);
                expect($messages->count())->equals(1);
                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'File',
                                    '_message' => 'Image should have max 800x800 resolution',
                                    '_field'   => 'file',
                                    '_code'    => '0',
                                ]
                            ),
                        ],
                    ]
                );

                expect($expectedMessages)->equals($messages);
            }
        );
    }

    /**
     * Tests file validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-23
     */
    public function testMultipleField()
    {
        $this->specify(
            'The file validator does not validates correctly with multiple field',
            function () {
                $validation = new Validation();
                $validation->add(
                    ['file', 'anotherFile'],
                    new File(
                        [
                            'maxSize'       => [
                                'file'        => '500K',
                                'anotherFile' => '600K',
                            ],
                            'allowedTypes'  => ['image/jpeg', 'image/png'],
                            'maxResolution' => [
                                'file'        => '800x800',
                                'anotherFile' => '900x900',
                            ],
                            'minResolution' => '1x1',
                            'message'       => [
                                'file'        => 'Image should have max 800x800 resolution',
                                'anotherFile' => 'Image should have max 900x900 resolution',
                            ],
                        ]
                    )
                );
                $messages = $validation->validate(['file' => $this->files[2], 'anotherFile' => $this->files[2]]);
                expect($messages->count())->equals(0);
                $messages = $validation->validate(['file' => $this->files[2], 'anotherFile' => $this->files[3]]);
                expect($messages->count())->equals(1);
                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'File',
                                    '_message' => 'Image should have max 900x900 resolution',
                                    '_field'   => 'anotherFile',
                                    '_code'    => '0',
                                ]
                            ),
                        ],
                    ]
                );

                expect($expectedMessages)->equals($messages);
                $messages = $validation->validate(['file' => $this->files[3], 'anotherFile' => $this->files[3]]);
                expect($messages->count())->equals(2);
                $expectedMessages = Validation\Message\Group::__set_state(
                    [
                        '_messages' => [
                            0 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'File',
                                    '_message' => 'Image should have max 800x800 resolution',
                                    '_field'   => 'file',
                                    '_code'    => '0',
                                ]
                            ),
                            1 => Validation\Message::__set_state(
                                [
                                    '_type'    => 'File',
                                    '_message' => 'Image should have max 900x900 resolution',
                                    '_field'   => 'anotherFile',
                                    '_code'    => '0',
                                ]
                            ),
                        ],
                    ]
                );

                expect($expectedMessages)->equals($messages);
            }
        );
    }
}
