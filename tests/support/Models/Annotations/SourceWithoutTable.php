<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models\Annotations;

use Phalcon\Annotations\Models\MetaData\Source;
use Phalcon\Mvc\Model;

// @phpstan-ignore arguments.count (Missing table is intentional for this regression fixture.)
#[Source]
class SourceWithoutTable extends Model
{
}
