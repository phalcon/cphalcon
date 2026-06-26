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

namespace Phalcon\Tests\Unit\Config\Adapter\Php;

use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Exceptions\CannotLoadConfigFile;
use Phalcon\Tests\AbstractUnitTestCase;

use function basename;
use function uniqid;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    public function testConfigAdapterPhpConstructThrowsWhenFileMissing(): void
    {
        $filePath = uniqid('/nonexistent-') . '.php';

        $this->expectException(CannotLoadConfigFile::class);
        $this->expectExceptionMessage(
            'Configuration file ' . basename($filePath) . ' cannot be loaded'
        );

        new Php($filePath);
    }
}
