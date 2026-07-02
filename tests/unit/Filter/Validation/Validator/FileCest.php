<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Validation\Validator;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File;
use UnitTester;

class FileCest
{
    /**
     * Tests File validator with `ignoreCheckUploadedFile = true`
     *
     * This test creates a temporary file instead of relying on
     * a static file under `tests/_data` to make it fully
     * self-contained and environment independent.
     *
     * @param UnitTester $I
     */
    public function fileIgnoreCheckUploadedFile(UnitTester $I): void
    {
        $I->wantToTest('Filter\Validation\Validator\File - ignoreCheckUploadedFile works');

        $validation = new Validation();
        $validation->add(
            'file',
            new File([
                'maxSize'                 => '2M',
                'ignoreCheckUploadedFile' => true,
                'allowEmpty'              => false,
                'types'                   => ['text/plain'],
            ])
        );

        // Create a temporary file to simulate an uploaded file
        $tmpFile = tempnam(sys_get_temp_dir(), 'phalcon_test_');
        file_put_contents($tmpFile, 'dummy content');

        // Fake uploaded file array
        $fakeFile = [
            'name'     => 'test.txt',
            'type'     => 'text/plain',
            'tmp_name' => $tmpFile,
            'error'    => 0,
            'size'     => filesize($tmpFile),
        ];

        $messages = $validation->validate([
            'file' => $fakeFile,
        ]);

        $I->assertEmpty($messages);

        // Clean up the temporary file
        @unlink($tmpFile);
    }
}
