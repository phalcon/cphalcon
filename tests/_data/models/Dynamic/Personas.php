<?php

namespace Phalcon\Test\Models\Dynamic;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\Dynamic\Personas
 *
 * @package Phalcon\Test\Models\Dynamic
 *
 * @property string $cedula
 * @property int $tipo_documento_id
 * @property string $nombres
 * @property string $telefono
 * @property string $direccion
 * @property string $email
 * @property string $fecha_nacimiento
 * @property int $ciudad_id
 * @property int $creado_at
 * @property float $cupo
 * @property string $estado
 *
 * @method static Personas findFirst($parameters = null)
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Personas extends Model
{
    public function initialize()
    {
        $this->useDynamicUpdate(true);
    }
}
