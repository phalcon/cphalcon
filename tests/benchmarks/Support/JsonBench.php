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

namespace Phalcon\Tests\Benchmarks\Support;

use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Tests\Benchmarks\Apps\Rest\Fixture;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class JsonBench
{
    private Encode $encode;

    private string $expected = '';

    private array $rows = [];

    public function setUp(): void
    {
        $this->encode   = new Encode();
        $this->rows     = (new Fixture())->rows(20);
        $this->expected = (string) json_encode($this->rows, 79);
    }

    /**
     * 20 rows with the default options of the helper (79).
     */
    public function benchEncode(): void
    {
        if ($this->expected !== ($this->encode)($this->rows)) {
            throw new RuntimeException('Encode returned an unexpected value');
        }
    }
}
