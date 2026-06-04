<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\AccessDenied;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;
use Phalcon\Auth\Exceptions\DataMustContainIdKey;
use Phalcon\Auth\Exceptions\DoesNotImplement;
use Phalcon\Auth\Exceptions\FileCannotRead;
use Phalcon\Auth\Exceptions\FileDoesNotContainJson;
use Phalcon\Auth\Exceptions\FileDoesNotExist;
use Phalcon\Auth\Exceptions\FileNotValidJson;
use Phalcon\Tests\AbstractUnitTestCase;
use RuntimeException;

final class ExceptionTest extends AbstractUnitTestCase
{
    public function testAccessDenied(): void
    {
        $exception = new AccessDenied('action', 'login');

        $this->assertSame(
            "Access denied for action 'login'",
            $exception->getMessage()
        );
    }

    public function testConfigRequiresNonEmptyValue(): void
    {
        $exception = new ConfigRequiresNonEmptyValue(
            'Stream adapter',
            'file'
        );

        $this->assertSame(
            "Stream adapter requires a non-empty 'file'",
            $exception->getMessage()
        );
    }

    public function testConfigRequiresNonEmptyValueWithSuffix(): void
    {
        $exception = new ConfigRequiresNonEmptyValue(
            'Model adapter',
            'model',
            ' class name'
        );

        $this->assertSame(
            "Model adapter requires a non-empty 'model' class name",
            $exception->getMessage()
        );
    }

    public function testDataMustContainIdKey(): void
    {
        $exception = new DataMustContainIdKey();

        $this->assertStringContainsString('id', $exception->getMessage());
    }

    public function testDoesNotImplement(): void
    {
        $exception = new DoesNotImplement('Adapter', 'RememberAdapter');

        $this->assertSame(
            "Adapter does not implement 'RememberAdapter'",
            $exception->getMessage()
        );
    }

    public function testStreamFileCannotRead(): void
    {
        $exception = new FileCannotRead('/path/to/file.json');

        $this->assertSame(
            'Stream adapter cannot read file: /path/to/file.json',
            $exception->getMessage()
        );
    }

    public function testStreamFileDoesNotContainJson(): void
    {
        $exception = new FileDoesNotContainJson('/p.json');

        $this->assertStringContainsString('/p.json', $exception->getMessage());
        $this->assertStringContainsString('JSON array', $exception->getMessage());
    }

    public function testStreamFileDoesNotExist(): void
    {
        $exception = new FileDoesNotExist('/missing.json');

        $this->assertSame(
            'Stream adapter file does not exist: /missing.json',
            $exception->getMessage()
        );
    }

    public function testStreamFileNotValidJson(): void
    {
        $previous  = new RuntimeException('json error');
        $exception = new FileNotValidJson('/bad.json', $previous);

        $this->assertStringContainsString('/bad.json', $exception->getMessage());
        $this->assertSame($previous, $exception->getPrevious());
    }
}
