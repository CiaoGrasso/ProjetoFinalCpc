from django.db import models

class PotentiometerDataMixer(models.Model):
    numero_serial = models.CharField(max_length=100)
    instrumento_db = models.FloatField(null=True, blank=True)
    mixer_db = models.FloatField(null=True, blank=True)
    mute_state = models.BooleanField()
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.numero_serial


class PotentiometerDataInput(models.Model):
    numero_serial = models.CharField(max_length=100)
    instrumento_db = models.FloatField(null=True, blank=True)

    def __str__(self):
        return self.numero_serial