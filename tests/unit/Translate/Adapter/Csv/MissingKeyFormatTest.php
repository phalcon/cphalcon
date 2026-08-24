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

namespace Phalcon\Tests\Unit\Translate\Adapter\Csv;

use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class MissingKeyFormatTest extends AbstractUnitTestCase
{
    /**
     * A missing key must be returned as-is, never fed to vsprintf as a format
     * string, so a request-derived key with format specifiers cannot trigger a
     * format-string error / DoS (CWE-134).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testTranslateAdapterCsvMissingKeyIsNotAFormatString(): void
    {
        $adapter = new Csv(
            new InterpolatorFactory(),
            [
                'content'             => Talon::settings()->supportPath('assets/translation/csv/en.csv'),
                'defaultInterpolator' => 'indexedArray',
            ]
        );

        // A missing key referencing a non-existent positional argument would
        // raise an error if it were used as a vsprintf format string.
        $result = $adapter->query('%9$s', ['only-one']);

        $this->assertSame('%9$s', $result);
    }
}
