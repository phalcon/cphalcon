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

namespace Phalcon\Tests\Unit\Html\Escaper\Fake;

use Phalcon\Html\Escaper\HtmlEscaper;

final class FakeHtmlEscaper extends HtmlEscaper
{
    public string $last = '';

    public function escape(?string $input = null): string
    {
        $this->last = (string) $input;

        return '<<<' . parent::escape($input) . '>>>';
    }
}
