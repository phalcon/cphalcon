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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Files;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Files;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\BackupGlobals;

use const UPLOAD_ERR_NO_FILE;
use const UPLOAD_ERR_OK;

#[BackupGlobals(true)]
final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * allowEmpty with every file missing (UPLOAD_ERR_NO_FILE) -> passes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorFilesValidateAllowEmptyAllNoFile(): void
    {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];

        $files = new Files(
            [
                'allowEmpty'   => true,
                'allowedTypes' => ['image/jpeg'],
            ]
        );

        $validation = new Validation();
        $validation->add('photos', $files);

        $data = [
            'photos' => [
                'name'     => ['', ''],
                'type'     => ['', ''],
                'tmp_name' => ['', ''],
                'error'    => [UPLOAD_ERR_NO_FILE, UPLOAD_ERR_NO_FILE],
                'size'     => [0, 0],
            ],
        ];

        $messages = $validation->validate($data);

        $this->assertCount(0, $messages);
    }

    /**
     * A multi-file node with no files selected -> nothing to validate, passes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorFilesValidateEmptyFileList(): void
    {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];

        $files = new Files(
            [
                'allowedTypes' => ['image/jpeg'],
            ]
        );

        $validation = new Validation();
        $validation->add('photos', $files);

        $data = [
            'photos' => [
                'name'     => [],
                'type'     => [],
                'tmp_name' => [],
                'error'    => [],
                'size'     => [],
            ],
        ];

        $messages = $validation->validate($data);

        $this->assertCount(0, $messages);
    }
    /**
     * Multiple files, the first one invalid -> one message, fail-fast.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorFilesValidateMultipleFailsFast(): void
    {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];

        $files = new Files(
            [
                'allowedTypes'     => ['image/jpeg', 'image/png'],
                'messageFileEmpty' => 'File is empty',
                'messageIniSize'   => 'Ini size is not valid',
                'messageValid'     => 'File is not valid',
            ]
        );

        $validation = new Validation();
        $validation->add('photos', $files);

        // Transposed multi-file node; empty tmp_name makes checkIsUploadedFile()
        // return false without requiring a real uploaded file.
        $data = [
            'photos' => [
                'name'     => ['a.jpg', 'b.png'],
                'type'     => ['image/jpeg', 'image/png'],
                'tmp_name' => ['', ''],
                'error'    => [UPLOAD_ERR_OK, UPLOAD_ERR_OK],
                'size'     => [1024, 2048],
            ],
        ];

        $messages = $validation->validate($data);

        // Fail-fast: only the first bad file is reported.
        $this->assertCount(1, $messages);
        $this->assertSame('File is empty', $messages->offsetGet(0)->getMessage());
    }

    /**
     * A single-file (non-multiple) node still validates like File.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorFilesValidateSingleFileShape(): void
    {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];

        $files = new Files(
            [
                'allowedTypes'     => ['image/jpeg'],
                'messageFileEmpty' => 'File is empty',
            ]
        );

        $validation = new Validation();
        $validation->add('photo', $files);

        $data = [
            'photo' => [
                'name'     => 'a.jpg',
                'type'     => 'image/jpeg',
                'tmp_name' => '',
                'error'    => UPLOAD_ERR_OK,
                'size'     => 1024,
            ],
        ];

        $messages = $validation->validate($data);

        $this->assertCount(1, $messages);
        $this->assertSame('File is empty', $messages->offsetGet(0)->getMessage());
    }
}
