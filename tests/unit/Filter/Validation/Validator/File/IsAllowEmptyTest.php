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
use Phalcon\Filter\Validation\Validator\File\MimeType;
use Phalcon\Tests\AbstractUnitTestCase;

use const UPLOAD_ERR_NO_FILE;
use const UPLOAD_ERR_OK;

final class IsAllowEmptyTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFilterValidationValidatorFileIsAllowEmpty(): void
    {
        // True path 1: empty array value → empty($value) returns true
        $validator  = new MimeType(['types' => ['image/jpeg'], 'allowEmpty' => true]);
        $validation = new Validation();
        $validation->add('file', $validator);

        $messages = $validation->validate(['file' => []]);
        $this->assertCount(0, $messages, 'Empty value skips validator');

        // True path 2: UPLOAD_ERR_NO_FILE → explicit no-file error skips validator
        $validator  = new MimeType(['types' => ['image/jpeg'], 'allowEmpty' => true]);
        $validation = new Validation();
        $validation->add('file', $validator);

        $messages = $validation->validate(['file' => ['error' => UPLOAD_ERR_NO_FILE]]);
        $this->assertCount(0, $messages, 'UPLOAD_ERR_NO_FILE skips validator');

        // False path: UPLOAD_ERR_OK with no actual file → isAllowEmpty returns false,
        // validator runs, checkIsUploadedFile('') fails → message appended
        $validator  = new MimeType(['types' => ['image/jpeg'], 'allowEmpty' => true]);
        $validation = new Validation();
        $validation->add('file', $validator);

        $fileData = [
            'name'     => 'test.jpg',
            'type'     => 'image/jpeg',
            'tmp_name' => '',
            'error'    => UPLOAD_ERR_OK,
            'size'     => 1024,
        ];

        $messages = $validation->validate(['file' => $fileData]);
        $this->assertCount(1, $messages, 'Non-empty file with UPLOAD_ERR_OK runs validator');
    }
}
