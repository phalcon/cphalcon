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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\File;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\BackupGlobals;

use const UPLOAD_ERR_NO_FILE;
use const UPLOAD_ERR_OK;

#[BackupGlobals(true)]
final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileValidate(): void
    {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];

        $file = new File(
            [
                'allowedTypes'     => ['image/jpeg', 'image/png'],
                'messageFileEmpty' => 'File is empty',
                'messageIniSize'   => 'Ini size is not valid',
                'messageValid'     => 'File is not valid',
            ]
        );

        $validation = new Validation();
        $validation->add('file', $file);

        // Empty tmp_name + UPLOAD_ERR_OK causes checkIsUploadedFile to return
        // false without requiring an actual uploaded file
        $fileData = [
            'name'     => 'test.jpg',
            'type'     => 'image/jpeg',
            'tmp_name' => '',
            'error'    => UPLOAD_ERR_OK,
            'size'     => 1024,
        ];

        $messages = $validation->validate(['file' => $fileData]);
        $this->assertCount(1, $messages);

        $expected = 'File is empty';
        $actual   = $messages->offsetGet(0)->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileValidateAllowedTypes(): void
    {
        $options    = [
            'allowedTypes'     => ['image/jpeg', 'image/png'],
            'maxSize'          => '0.5M',
            'minSize'          => '0.1M',
            'maxResolution'    => '800x600',
            'minResolution'    => '200x200',
            'messageFileEmpty' => 'File is empty',
            'messageIniSize'   => 'Ini size is not valid',
            'messageValid'     => 'File is not valid',
        ];
        $file       = new File($options);
        $validators = $file->getValidators();

        $this->assertCount(5, $validators);

        $expected  = File\MimeType::class;
        $actual    = $validators[0];
        $this->assertInstanceOf($expected, $actual);

        $expected  = File\Size\Max::class;
        $actual    = $validators[1];
        $this->assertInstanceOf($expected, $actual);

        $expected  = File\Size\Min::class;
        $actual    = $validators[2];
        $this->assertInstanceOf($expected, $actual);

        $expected  = File\Resolution\Max::class;
        $actual    = $validators[3];
        $this->assertInstanceOf($expected, $actual);

        $expected  = File\Resolution\Min::class;
        $actual    = $validators[4];
        $this->assertInstanceOf($expected, $actual);
    }
}
