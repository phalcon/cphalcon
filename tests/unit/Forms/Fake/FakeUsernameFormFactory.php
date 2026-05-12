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

namespace Phalcon\Tests\Unit\Forms\Fake;

use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;

final class FakeUsernameFormFactory
{
    public function __invoke(?object $entity): Form
    {
        return (new Form($entity))->load(new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]), new FormsLocator());
    }
}
