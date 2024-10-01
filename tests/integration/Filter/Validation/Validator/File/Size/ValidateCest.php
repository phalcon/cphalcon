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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\File\Size;

use Codeception\Example;
use Codeception\Stub;
use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File\Size\Equal;
use Phalcon\Filter\Validation\Validator\File\Size\Max;
use Phalcon\Filter\Validation\Validator\File\Size\Min;

class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\File\Size :: validate
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @return void
     * @throws Validation\Exception
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-09-28
     *
     * @dataProvider getExamples
     *
     */
    public function filterValidationValidatorFileSize(
        IntegrationTester $I,
        Example $example
    ) {
        $class   = $example['class'];
        $options = $example['options'];

        $I->wantToTest($class . ' - validate');

        $files   = $_FILES ?? [];
        $server  = $_SERVER ?? [];
        $_SERVER = [
            'REQUEST_METHOD' => 'POST',
        ];

        $_FILES = [
            'thumbnail' => [
                'name'      => 'IMG-20180403-WA0000.jpg',
                'full_path' => 'IMG-20180403-WA0000.jpg',
                'type'      => 'image/jpeg',
                'tmp_name'  => '/tmp/phpsjLIQJ',
                'error'     => 0,
                'size'      => 11768,
            ],
        ];

        $validator = Stub::construct(
            $class,
            [
                'options' => $options,
            ],
            [
                'checkIsUploadedFile' => function () {
                    return true;
                },
            ]
        );

        $validation = new Validation();
        $validation->add('thumbnail', $validator);

        $messages = $validation->validate($_FILES);

        $I->assertCount(0, $messages);

        $_FILES  = $files;
        $_SERVER = $server;
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\File\Size :: errors
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @return void
     * @throws Validation\Exception
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-09-28
     *
     * @dataProvider getExamplesErrors
     *
     */
    public function filterValidationValidatorFileSizeErrors(
        IntegrationTester $I,
        Example $example
    ) {
        $class   = $example['class'];
        $options = $example['options'];

        $I->wantToTest($class . ' - validate errors');

        $files   = $_FILES ?? [];
        $server  = $_SERVER ?? [];
        $_SERVER = [
            'REQUEST_METHOD' => 'POST',
        ];
        $_FILES  = [
            'thumbnail' => [
                'name'      => 'IMG-20180403-WA0000.jpg',
                'full_path' => 'IMG-20180403-WA0000.jpg',
                'type'      => 'image/jpeg',
                'tmp_name'  => '/tmp/phpsjLIQJ',
                'error'     => 0,
                'size'      => 11768,
            ],
        ];

        $validator = Stub::construct(
            $class,
            [
                'options' => $options,
            ],
            [
                'checkIsUploadedFile' => function () {
                    return true;
                },
            ]
        );

        $validation = new Validation();
        $validation->add('thumbnail', $validator);

        $messages = $validation->validate($_FILES);

        $I->assertCount(1, $messages);

        $expected = $example['message'];
        $actual   = $messages[0]->getMessage();
        $I->assertSame($expected, $actual);

        $_FILES  = $files;
        $_SERVER = $server;
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'class'   => Min::class,
                'options' => [
                    'size'    => '1K',
                    'message' => ':field is smaller than file size (:size)',
                ],
            ],
            [
                'class'   => Max::class,
                'options' => [
                    'size'    => '20K',
                    'message' => ':field is larger than file size (:size)',
                ],
            ],
            [
                'class'   => Equal::class,
                'options' => [
                    'size'    => '11768',
                    'message' => ':field is not equal to file size (:size)',
                ],
            ],
        ];
    }

    /**
     * @return array[]
     */
    private function getExamplesErrors(): array
    {
        return [
            [
                'class'   => Min::class,
                'message' => 'thumbnail is smaller than file size (20K)',
                'options' => [
                    'size'    => '20K',
                    'message' => ':field is smaller than file size (:size)',
                ],
            ],
            [
                'class'   => Min::class,
                'message' => 'thumbnail is smaller or equal than file size (11768)',
                'options' => [
                    'included' => true,
                    'size'     => '11768',
                    'message'  => ':field is smaller or equal than file size (:size)',
                ],
            ],
            [
                'class'   => Max::class,
                'message' => 'thumbnail is larger than file size (10K)',
                'options' => [
                    'size'    => '10K',
                    'message' => ':field is larger than file size (:size)',
                ],
            ],
            [
                'class'   => Max::class,
                'message' => 'thumbnail is larger or equal than file size (11768)',
                'options' => [
                    'included' => true,
                    'size'     => '11768',
                    'message'  => ':field is larger or equal than file size (:size)',
                ],
            ],
            [
                'class'   => Equal::class,
                'message' => 'thumbnail is not equal to file size (11700)',
                'options' => [
                    'size'    => '11700',
                    'message' => ':field is not equal to file size (:size)',
                ],
            ],
        ];
    }
}
