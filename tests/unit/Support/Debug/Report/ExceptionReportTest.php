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

namespace Phalcon\Tests\Unit\Support\Debug\Report;

use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Tests\AbstractUnitTestCase;

final class ExceptionReportTest extends AbstractUnitTestCase
{
    public function testMetaAndSections(): void
    {
        $report = new ExceptionReport('My\\Ex', 'boom', '/a.php', 7, true, 'https://cdn/');

        $this->assertSame('My\\Ex', $report->getClassName());
        $this->assertSame('boom', $report->getMessage());
        $this->assertSame('/a.php', $report->getFile());
        $this->assertSame(7, $report->getLine());
        $this->assertTrue($report->isShowBackTrace());
        $this->assertSame('https://cdn/', $report->getUri());

        $this->assertFalse($report->hasVariables());

        $item = new BacktraceItem('fn');
        $report->setBacktrace([$item])
            ->setRequest(['r' => 1])
            ->setServer(['s' => 2])
            ->setIncludedFiles(['/x.php'])
            ->setMemoryUsage(123)
            ->setPeakMemoryUsage(456)
            ->setVariables(['k' => 'v']);

        $this->assertSame([$item], $report->getBacktrace());
        $this->assertSame(['r' => 1], $report->getRequest());
        $this->assertSame(['s' => 2], $report->getServer());
        $this->assertSame(['/x.php'], $report->getIncludedFiles());
        $this->assertSame(123, $report->getMemoryUsage());
        $this->assertSame(456, $report->getPeakMemoryUsage());
        $this->assertSame(['k' => 'v'], $report->getVariables());
        $this->assertTrue($report->hasVariables());
    }
}
