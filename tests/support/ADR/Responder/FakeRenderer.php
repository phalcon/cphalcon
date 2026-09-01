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

namespace Phalcon\Tests\Support\ADR\Responder;

use Phalcon\Contracts\View\Renderer;

/**
 * Records what the responder asked to render, so the ADR tests never need a
 * real view.
 */
final class FakeRenderer implements Renderer
{
    public array $data = [];
    public string $template = '';

    public function render(string $path, array $params = []): string
    {
        $this->template = $path;
        $this->data     = $params;

        return '<h1>' . $path . '</h1>';
    }
}
