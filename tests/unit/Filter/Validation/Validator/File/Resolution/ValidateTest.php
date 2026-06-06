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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\File\Resolution;

use Phalcon\Filter\Validation;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Filter\Validation\Validator\File\Resolution\Fake\FakeEqual;
use Phalcon\Tests\Unit\Filter\Validation\Validator\File\Resolution\Fake\FakeMax;
use Phalcon\Tests\Unit\Filter\Validation\Validator\File\Resolution\Fake\FakeMin;
use PHPUnit\Framework\Attributes\BackupGlobals;
use PHPUnit\Framework\Attributes\DataProvider;

use function filesize;
use function supportDir;

#[BackupGlobals(true)]
final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * The fixture image example-png.png is 82x82.
     *
     * @return array<array{string, array}>
     */
    public static function getExamples(): array
    {
        return [
            // Equal: exact match passes
            [FakeEqual::class, ['resolution' => '82x82']],
            // Max: image is smaller than the maximum
            [FakeMax::class, ['resolution' => '100x100']],
            // Min: image is larger than the minimum
            [FakeMin::class, ['resolution' => '50x50']],
        ];
    }

    /**
     * @return array<array{string, array, string}>
     */
    public static function getExamplesErrors(): array
    {
        return [
            [
                FakeEqual::class,
                ['resolution' => '100x100'],
                'The resolution of the field thumbnail has to be equal 100x100',
            ],
            [
                FakeMax::class,
                ['resolution' => '50x50'],
                'File thumbnail exceeds the maximum resolution of 50x50',
            ],
            [
                FakeMin::class,
                ['resolution' => '100x100'],
                'File thumbnail can not have the minimum resolution of 100x100',
            ],
            // included = true makes the boundary itself fail
            [
                FakeMax::class,
                ['resolution' => '82x82', 'included' => true],
                'File thumbnail exceeds the maximum resolution of 82x82',
            ],
            [
                FakeMin::class,
                ['resolution' => '82x82', 'included' => true],
                'File thumbnail can not have the minimum resolution of 82x82',
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    #[DataProvider('getExamples')]
    public function testFilterValidationValidatorFileResolution(
        string $class,
        array $options
    ): void {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];
        $_FILES  = ['thumbnail' => $this->buildFile()];

        $validator  = new $class($options);
        $validation = new Validation();
        $validation->add('thumbnail', $validator);

        $messages = $validation->validate($_FILES);

        $this->assertCount(0, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-06
     */
    #[DataProvider('getExamplesErrors')]
    public function testFilterValidationValidatorFileResolutionErrors(
        string $class,
        array $options,
        string $message
    ): void {
        $_SERVER = ['REQUEST_METHOD' => 'POST'];
        $_FILES  = ['thumbnail' => $this->buildFile()];

        $validator  = new $class($options);
        $validation = new Validation();
        $validation->add('thumbnail', $validator);

        $messages = $validation->validate($_FILES);

        $this->assertCount(1, $messages);
        $this->assertSame($message, $messages[0]->getMessage());
    }

    /**
     * @return array<string, mixed>
     */
    private function buildFile(): array
    {
        $path = supportDir('assets/images/example-png.png');

        return [
            'name'     => 'example-png.png',
            'type'     => 'image/png',
            'tmp_name' => $path,
            'error'    => 0,
            'size'     => filesize($path),
        ];
    }
}
