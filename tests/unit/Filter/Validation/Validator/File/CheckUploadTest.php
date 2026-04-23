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
use Phalcon\Filter\Validation\Validator\File\Size\Equal;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Filter\Validation\Validator\File\Fake\FakeMimeType;
use PHPUnit\Framework\Attributes\BackupGlobals;

use const UPLOAD_ERR_INI_SIZE;
use const UPLOAD_ERR_PARTIAL;

#[BackupGlobals(true)]
final class CheckUploadTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileCheckUploadIsValidMissingKeys(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'POST';

        // File array has error=0 and tmp_name but is missing name/type/size
        $fileData = [
            'error'    => 0,
            'tmp_name' => '/some/fake/path',
        ];

        $validator  = new FakeMimeType(['types' => ['image/jpeg']]);
        $validation = new Validation();
        $validation->add('file', $validator);

        $messages = $validation->validate(['file' => $fileData]);

        $this->assertCount(1, $messages, 'Missing keys triggers invalid file message');
        $this->assertStringContainsString('file', $messages[0]->getMessage());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileCheckUploadMaxSizeIniSizeError(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'POST';

        $fileData = [
            'name'     => 'test.jpg',
            'type'     => 'image/jpeg',
            'tmp_name' => '',
            'error'    => UPLOAD_ERR_INI_SIZE,
            'size'     => 0,
        ];

        $validator  = new FakeMimeType(['types' => ['image/jpeg']]);
        $validation = new Validation();
        $validation->add('file', $validator);

        $messages = $validation->validate(['file' => $fileData]);

        $this->assertCount(1, $messages, 'UPLOAD_ERR_INI_SIZE triggers ini size message');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileSizeEqualValidateCheckUploadFails(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'POST';

        $fileData = [
            'name'     => 'test.txt',
            'type'     => 'text/plain',
            'tmp_name' => '',
            'error'    => UPLOAD_ERR_PARTIAL,
            'size'     => 0,
        ];

        $validator  = new Equal(['size' => '1K']);
        $validation = new Validation();
        $validation->add('file', $validator);

        $messages = $validation->validate(['file' => $fileData]);

        $this->assertCount(1, $messages, 'UPLOAD_ERR_PARTIAL triggers empty file message');
    }
}
